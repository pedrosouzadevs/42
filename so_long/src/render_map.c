/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:02:56 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/29 17:12:24 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_images(t_game *game)
{
	xpm_t* xpm;

	xpm = mlx_load_xpm42("assets/wall.xpm42");
	game->map.wall_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);

	xpm = mlx_load_xpm42("assets/floor.xpm42");
	game->map.collectible_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);

	xpm = mlx_load_xpm42("assets/wall.xpm42");
	game->map.exit_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);

	xpm = mlx_load_xpm42("assets/wall.xpm42");
	game->map.platform_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);

	xpm = mlx_load_xpm42("assets/floor.xpm42");
	game->map.floor_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);

	xpm = mlx_load_xpm42("assets/sf1_b.xpm42");
	game->player.image= mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
	mlx_delete_xpm42(xpm);
}
void render_map(t_game *game) {
	int y;
	int x;

	y = 0;
	while (game->map.map[y])
	{ // Percorre as linhas do mapa
		x = 0;
		while (game->map.map[y][x])
		{ // Percorre os caracteres da linha
			if (game->map.map[y][x] == '1')
				if (is_edge_wall(game))
					mlx_image_to_window(game->mlx, game->map.platform_img, x * TILE_SIZE, y * TILE_SIZE);
				else
					mlx_image_to_window(game->mlx, game->map.wall_img, x * TILE_SIZE, y * TILE_SIZE);
			else
			{
				mlx_image_to_window(game->mlx, game->map.floor_img, x * TILE_SIZE, y * TILE_SIZE);
				if (game->map.map[y][x] == 'E')
					mlx_image_to_window(game->mlx, game->map.exit_img, x * TILE_SIZE, y * TILE_SIZE);
				else if (game->map.map[y][x] == 'C')
					mlx_image_to_window(game->mlx, game->map.collectible_img, x * TILE_SIZE, y * TILE_SIZE);
				else if (game->map.map[y][x] == 'T')
					mlx_image_to_window(game->mlx, game->map.enemy_img, x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}

void	verify_wall(t_game *game)
{
	if (is_edge_wall(game))
		error_wall();
}
int	is_edge_wall(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (y == 0 || y == game->map.height - 1)
				if (x >= 0 && x <= game->map.width - 1)
					if (game->map.map[y][x] != '1')
					return (1);
			if (y > 0 && y < (game->map.height - 1))
				if (x == 0 || x == game->map.width - 1)
					if (game->map.map[y][x] != '1')
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	verify_map(t_game *game)
{
	int y = 0;
	int x = 0;

	while (game->map.map[y]) { // Percorre as linhas do mapa
		x = 0;
		while (game->map.map[y][x])
		{ // Percorre os caracteres da linha
			if (game->map.map[y][x] == 'E')
				game->map.exit++;
			if (game->map.map[y][x] == 'C')
				game->map.collectibles++;
			if (game->map.map[y][x] == 'P')
				game->map.player++;
			x++;
		}
		y++;
	}
	if (game->map.exit == 0 || game->map.collectibles == 0 || game->map.player == 0)
		error_none_player_exit_colec();
	if (game->map.exit > 1 || game->map.player > 1)
	{
		printf("Error\nMap must have no more than one exit and one player\n");
		exit(EXIT_FAILURE);
	}
	is_map_retangle(game);
}
void	find_player_position(t_game *game)
{
    int y = 0;
    while (game->map.map[y]) {
        int x = 0;
        while (game->map.map[y][x]) {
            if (game->map.map[y][x] == 'P') {
                game->player.x = x * TILE_SIZE;
                game->player.y = y * TILE_SIZE;
                return;
            }
            x++;
        }
        y++;
    }
}
void	error_wall(void)
{
	printf("Error\nMap must have walls on the edges\n");
	exit(EXIT_FAILURE);
}
void	error_none_player_exit_colec(void)
{
	printf("Error\nMap must have at least one exit, one collectible and one player\n");
	exit(EXIT_FAILURE);
}

void	is_map_retangle(t_game *game)
{
	if (game->map.width == game->map.height)
	{
		printf("Error\nMap must be a rectangle\n");
		exit(EXIT_FAILURE);
	}
}
