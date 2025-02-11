/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:38:51 by pdro              #+#    #+#             */
/*   Updated: 2025/02/11 15:27:03 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_images(t_game *game)
{
	xpm_t	*xpm;

	xpm = mlx_load_xpm42("assets/collectable/Water-stone-b.xpm42");
	game->map.collectible_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42("assets/exit/exit1_c.xpm42");
	game->map.exit_close_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42("assets/floor/floor.xpm42");
	game->map.floor_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42("assets/player/sf1_b.xpm42");
	game->player.image = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42("assets/exit/exit1_o.xpm42");
	game->map.exit_open_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42("assets/wall/wall.xpm42");
	game->map.wall_img = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	resize_images(game);
	game->map.exit_opened = false;
}

void	resize_images(t_game *game)
{
	mlx_resize_image(game->map.exit_close_img, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->map.exit_open_img, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->map.wall_img, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->map.floor_img, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->map.collectible_img, TILE_SIZE, TILE_SIZE);
	game->map.exit = 0;
	game->map.collectibles = 0;
	game->map.enemies = 0;
	game->map.player = 0;
	game->player.collected = 0;
	game->player.dist_traveled = 0;
}
