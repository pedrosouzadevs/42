/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:35:55 by pdro              #+#    #+#             */
/*   Updated: 2025/02/05 14:45:00 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_hook(void *param)
{
	t_game	*game;

	game = param;
	game->player.prev_x = game->player.x;
	game->player.prev_y = game->player.y;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	movement_with_collision(game);
	calculate_movement(game);
	// refresh_player(game);
	enemy_move(game);
	update_steps_display(game->mlx, game->player.count, 85, 10);
	exit_open(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Use .so_long map.ber\n");
		return (EXIT_FAILURE);
	}
	game = (t_game *)malloc(sizeof(t_game));
	read_map(argv, game);
	if (!game->map.map)
		error_readeble_map();
	game->mlx = mlx_init((game->map.width * TILE_SIZE),
			(game->map.height * TILE_SIZE), "So_long", true);
	if (!game->mlx)
	{
		printf("Erro: mlx não foi inicializado corretamente\n");
		exit(EXIT_FAILURE);
	}
	game->window = mlx_new_image(game->mlx, (game->map.width * TILE_SIZE),
			(game->map.height * TILE_SIZE));
	init_images(game);
	verify_map(game);
	find_player_position(game);
	render_map(game);
	mlx_image_to_window(game->mlx, game->player.image, game->player.x,
		game->player.y);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	free_game_resources(game);
	return (0);
}

int	error_readeble_map(void)
{
	ft_printf("Error: map is not readeble\n");
	return (EXIT_FAILURE);
}

void clear_text_area(t_game *game, int x, int y, int width, int height, uint32_t bg_color)
{
	int	i;
	int	j;
	xpm_t *square;

	// Carregar a textura

 	square = mlx_load_xpm42("assets/wall/square.xpm42");
    if (!square)
    {
        printf("Erro: não foi possível carregar a textura\n");
        return;
    }

    // Se já existe uma imagem anterior, deletamos antes
    if (game->map.square_img)
        mlx_delete_image(game->mlx, game->map.square_img);

    // Criar a nova imagem a partir da textura
    game->map.square_img = mlx_texture_to_image(game->mlx, &square->texture);
    if (!game->map.square_img)
    {
        printf("Erro: não foi possível converter textura para imagem\n");
        mlx_delete_xpm42(square);
        return;
    }

	mlx_delete_xpm42(square);
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			mlx_put_pixel(game->map.square_img, i, j, bg_color);
			j++;
		}
		i++;
	}

	mlx_image_to_window(game->mlx, game->map.square_img, x, y);
}

void update_steps_display(t_game *game, int steps, int x, int y)
{
	int width = 100; // Largura suficiente para cobrir o texto antigo
	int height = 30;
	uint32_t bg_color = 0x000000FF; // Cor preta para cobrir

	// Apagar área antiga
	clear_text_area(game->mlx, x, y, width, height, bg_color);

	// Escrever novo texto
	char *step_str = ft_itoa(steps);
	mlx_put_string(game->mlx, "Moves: ", x, y);
	mlx_put_string(game->mlx, step_str, x + 80, y);
	free(step_str);
}
