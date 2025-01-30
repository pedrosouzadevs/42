/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:02:21 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/29 17:13:02 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int is_wall(t_game *game, int x, int y)
{
	int map_x1;
	int map_y1;
	int map_x2;
	int map_y2;

	map_x1 = x / TILE_SIZE;
	map_y1 = y / TILE_SIZE;
	map_x2 = (x + TILE_SIZE - 1) / TILE_SIZE;
	map_y2 = (y + TILE_SIZE - 1) / TILE_SIZE;
	return (game->map.map[map_y1][map_x1] == '1' ||
	        game->map.map[map_y1][map_x2] == '1' ||
	        game->map.map[map_y2][map_x1] == '1' ||
	        game->map.map[map_y2][map_x2] == '1');
}

void ft_hook(void* param)
{
	t_game *game;

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
void	exit_open(t_game *game)
{
	if (game->player.collected == game->map.collectibles)
	{
		if (game->map.exit_close_img)
			mlx_delete_image(game->mlx, game->map.exit_close_img);
		mlx_image_to_window(game->mlx, game->map.exit_open_img, game->map.exit_x * TILE_SIZE, game->map.exit_y * TILE_SIZE);
		game->map.exit_opened = true;
	}
}

void	refresh_player(t_game *game)
{
	xpm_t* xpm;

	if (game->player.collected == game->map.collectibles)
	{
		mlx_delete_image(game->mlx, game->player.image);
		xpm = mlx_load_xpm42("assets/player/war_b.xpm42");
		game->player.image = mlx_texture_to_image(game->mlx, &xpm->texture);
		mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
	    mlx_image_to_window(game->mlx, game->player.image, game->player.x, game->player.y);
	}
	else
	{
		mlx_delete_image(game->mlx, game->player.image);
		xpm = mlx_load_xpm42("assets/player/sf1_b.xpm42");
		game->player.image = mlx_texture_to_image(game->mlx, &xpm->texture);
		mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
		mlx_image_to_window(game->mlx, game->player.image, game->player.x, game->player.y);
	}

}
void calculate_movement(t_game *game)
{
	int		x;
	int		y;

	x = abs(game->player.x - game->player.prev_x);
	y = abs(game->player.y - game->player.prev_y);
	game->player.dist_traveled += x + y;
	if (game->player.dist_traveled >= TILE_SIZE)
	{
		game->player.dist_traveled = 0;
		game->player.count++;
		ft_printf("count: %d\n", game->player.count);
	}
}
void	movement_with_collision(t_game *game)
{
	next_tile(game);
	if (game->map.exit_opened && game->player.x == game->map.exit_x * TILE_SIZE && game->player.y == game->map.exit_y * TILE_SIZE)
	{
		ft_printf("You win\n");
		mlx_close_window(game->mlx);
	}
	if (game->map.map[game->player.y / TILE_SIZE][game->player.x / TILE_SIZE] == 'C')
	{
		game->player.collected++;
		game->map.map[game->player.y / TILE_SIZE][game->player.x / TILE_SIZE] = '0';
		render_map(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && !is_wall(game, game->player.x, game->player.y - MOVE_SIZE))
		game->player.y -= MOVE_SIZE;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) && !is_wall(game, game->player.x, game->player.y + MOVE_SIZE))
		game->player.y += MOVE_SIZE;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) && !is_wall(game, game->player.x - MOVE_SIZE, game->player.y))
		game->player.x -= MOVE_SIZE;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D) && !is_wall(game, game->player.x + MOVE_SIZE, game->player.y))
		game->player.x += MOVE_SIZE;
}
void	next_tile(t_game *game)
{
	game->player.north = game->map.map[(game->player.y - MOVE_SIZE) / TILE_SIZE][(game->player.x) / TILE_SIZE];
	game->player.south = game->map.map[(game->player.y + MOVE_SIZE + (TILE_SIZE - MOVE_SIZE)) / TILE_SIZE][(game->player.x) / TILE_SIZE];
	game->player.east = game->map.map[(game->player.y) / TILE_SIZE][(game->player.x + MOVE_SIZE + (TILE_SIZE - MOVE_SIZE)) / TILE_SIZE];
	game->player.west = game->map.map[(game->player.y) / TILE_SIZE][(game->player.x - MOVE_SIZE) / TILE_SIZE];
}
int main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
	{
		ft_printf("Use .so_long map.ber\n");
		return (EXIT_FAILURE);
	}
	game = (t_game *)malloc(sizeof(t_game));
	game->map.map = read_map(argv, game);
	if (!game->map.map)
	{
		ft_printf("Error: map is not readeble\n");
		return (EXIT_FAILURE);
	}
	game->mlx = mlx_init((game->map.width * TILE_SIZE), (game->map.height * TILE_SIZE), "Meu Jogo 2D", true);
    game->window= mlx_new_image(game->mlx, (game->map.width * TILE_SIZE), (game->map.height * TILE_SIZE));
	init_images(game);
	verify_map(game);
	// verify_wall(game);
	find_player_position(game);
	render_map(game);
	mlx_image_to_window(game->mlx, game->player.image, game->player.x, game->player.y);
    mlx_loop_hook(game->mlx, ft_hook, game);
    mlx_loop(game->mlx);  // Inicia o loop do MinilibX
	free_game_resources(game);
    return (0);
}
