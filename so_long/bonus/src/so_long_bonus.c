/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:35:55 by pdro              #+#    #+#             */
/*   Updated: 2025/02/14 18:02:32 by pedro-hm         ###   ########.fr       */
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
	refresh_player(game);
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
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	read_map(argv, game);
	read_map_route(argv, game);
	game->mlx = mlx_init((game->map.width * TILE_SIZE),
			(game->map.height * TILE_SIZE), "So_long", true);
	game->window = mlx_new_image(game->mlx, (game->map.width * TILE_SIZE),
			(game->map.height * TILE_SIZE));
	init_images(game);
	verify_map(game);
	render_map(game);
	put_player_enemy_in_map(game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	free_game_resources(game);
	return (0);
}

void	put_player_enemy_in_map(t_game *game)
{
	find_enemy_position(game);
	mlx_image_to_window(game->mlx, game->player.image, game->player.x,
		game->player.y);
	if (game->enemy.x != 0 && game->enemy.y != 0)
		mlx_image_to_window(game->mlx, game->enemy.image,
			game->enemy.x * TILE_SIZE, game->enemy.y * TILE_SIZE);
}
