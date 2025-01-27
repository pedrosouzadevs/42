/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:02:21 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/27 17:18:11 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int is_wall(t_game *game, int x, int y)
{
    int map_x = x / TILE_SIZE;
    int map_y = y / TILE_SIZE;
    return (game->map.map[map_y][map_x] == '1');
}

void	setting_jump(t_game *game)
{
	game->player.jump = 50;
	game->player.initial_y = game->player.y;  // Registrar a posição inicial do salto
}

void ft_hook(void* param)
{
    t_game *game;

    game = param;

	setting_jump(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);

    // Movimento lateral
    if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        game->player.x -= 50;
    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        game->player.x  += 50;

    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
    {
        game->player.y  -= 50;
    }
    // Movimento vertical (salto)
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->player.y  += 50;
	}
	mlx_clear_window(game->mlx, game->window);
	render_map(game);
    mlx_image_to_window(game->mlx, game->player.image, game->player.x, game->player.y);
}

int main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
	{
		write(2, "Use ./so_long mapa.ber\n", 27);
		return 1;
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		write(2, "Erro ao alocar memória\n", 23);
		return 1;
	}
	game->map.map = read_map(argv, game);
	if (!game->map.map)
	{
		write(2, "Erro ao ler o mapa\n", 20);
		return 1;
	}
	game->mlx = mlx_init((game->map.width * 100), (game->map.height * 100), "Meu Jogo 2D", true);
    if (!game->mlx) {
        write(2, "Erro ao inicializar o MinilibX\n", 30);
		free(game);
        return 1;
    }
    game->window= mlx_new_image(game->mlx, (game->map.width * 100), (game->map.height * 100));
	if (!game->window)
	{
		write(2, "Erro ao criar a janela\n", 24);
		free(game);
		return 1;
	}
	init_images(game);
	verify_map(game);
	verify_wall(game);
	find_player_position(game);
	render_map(game);
	mlx_image_to_window(game->mlx, game->player.image, game->player.x, game->player.y);
    mlx_loop_hook(game->mlx, ft_hook, game);
    mlx_loop(game->mlx);  // Inicia o loop do MinilibX
	free_game_resources(game);
    return (0);
}
