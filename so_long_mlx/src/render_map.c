/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdro <pdro@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 19:28:55 by pdro              #+#    #+#             */
/*   Updated: 2025-01-26 19:28:55 by pdro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_images(t_game *game)
{
    int img_width;
    int img_height;

    game->map.wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &img_width, &img_height);
    game->map.collectible_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &img_width, &img_height);
    game->map.exit_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &img_width, &img_height);
    game->map.floor_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &img_width, &img_height);
    game->player.image = mlx_xpm_file_to_image(game->mlx, "assets/sf1_b.xpm", &img_width, &img_height);
}
void render_map(t_game *game) {
    int y;
    int x;
	int screen_x;
	int screen_y;

	y = 0;
    while (game->map.map[y])
	{ // Percorre as linhas do mapa
        x = 0;
        while (game->map.map[y][x])
		{ // Percorre os caracteres da linha
            screen_x = x * TILE_SIZE;
            screen_y = y * TILE_SIZE;
            if (game->map.map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->window, game->map.wall_img, screen_x, screen_y);
            else
                mlx_put_image_to_window(game->mlx, game->window, game->map.floor_img, screen_x, screen_y);
			if (game->map.map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->window, game->map.exit_img, screen_x, screen_y);
            else if (game->map.map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, game->map.collectible_img, screen_x, screen_y);
            else if (game->map.map[y][x] == 'T')
                mlx_put_image_to_window(game->mlx, game->window, game->map.enemy_img, screen_x, screen_y);
            x++;
        }
        y++;
    }
}

void	verify_wall(t_game *game)
{
	int y;
	int x;

	y = 0;
	printf("width: %d, height: %d\n", game->map.width, game->map.height);

	while (y < game->map.height) { // Percorre as linhas do mapa
		x = 0;
		while (x < game->map.width)
		{ // Percorre os caracteres da linha
			printf("y: %d, x: %d, map: %c\n", y, x, game->map.map[y][x]);
			// printf("game->map.width: %d, game->map.height: %d\n", game->map.width, game->map.height);
			if (y == 0 || y == game->map.height - 1)
				if (x >= 0 && x <= game->map.width - 1)
					if (game->map.map[y][x] != '1')
					{
						printf("Error\nMap must have walls on the  asd edges\n");
						exit(EXIT_FAILURE);
					}

			if (y > 0 && y < (game->map.height - 1))
				if (x == 0 || x == game->map.width - 1)
					if (game->map.map[y][x] != '1')
					{
						printf("Error\nMap must have walls on the edges\n");
						exit(EXIT_FAILURE);
					}
			x++;
		}
		y++;
	}
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
	{
		printf("Error\nMap must have at least one exit, one collectible and one player\n");
		exit(EXIT_FAILURE);
	}
	if (game->map.exit > 1 || game->map.player > 1)
	{
		printf("Error\nMap must have no more than one exit and one player\n");
		exit(EXIT_FAILURE);
	}
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
