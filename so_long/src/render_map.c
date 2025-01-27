/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:02:56 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/27 15:55:07 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_images(t_game *game)
{
	xpm_t* xpm;

    // game->map.wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &img_width, &img_height);
	xpm = mlx_load_xpm42("assets/wall.xpm42");
	game->map.wall_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);

    // game->map.collectible_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &img_width, &img_height);
	xpm = mlx_load_xpm42("assets/floor.xpm42");
	game->map.collectible_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);

    // game->map.exit_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &img_width, &img_height);
	xpm = mlx_load_xpm42("assets/wall.xpm42");
	game->map.exit_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);

    // game->map.floor_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &img_width, &img_height);
	xpm = mlx_load_xpm42("assets/floor.xpm42");
	game->map.floor_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);

    // game->player.image = mlx_xpm_file_to_image(game->mlx, "assets/sf1_b.xpm", &img_width, &img_height);
	xpm = mlx_load_xpm42("assets/sf1_b.xpm42");
	if (!xpm) {
    write(2, "Erro ao carregar textura wall.xpm42\n", 36);
    exit(EXIT_FAILURE);
	}
	game->player.image= mlx_texture_to_image(game->mlx, &xpm->texture);
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
				mlx_image_to_window(game->mlx, game->map.wall_img, x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_image_to_window(game->mlx, game->map.floor_img, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map.map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->map.exit_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->map.collectible_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'T')
				mlx_image_to_window(game->mlx, game->map.enemy_img, x * TILE_SIZE, y * TILE_SIZE);
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
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (y == 0 || y == game->map.height - 1)
				if (x >= 0 && x <= game->map.width - 1)
					if (game->map.map[y][x] != '1')
					error_wall();
			if (y > 0 && y < (game->map.height - 1))
				if (x == 0 || x == game->map.width - 1)
					if (game->map.map[y][x] != '1')
					error_wall();
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
		error_none_player_exit_colec();
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
