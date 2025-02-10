/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:38:34 by pdro              #+#    #+#             */
/*   Updated: 2025/02/10 16:13:44 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	refresh_player(t_game *game)
{
	xpm_t	*xpm;

	if (game->player.collected == game->map.collectibles)
	{
		mlx_delete_image(game->mlx, game->player.image);
		xpm = mlx_load_xpm42("assets/player/war_b.xpm42");
		game->player.image = mlx_texture_to_image(game->mlx, &xpm->texture);
		mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
		mlx_image_to_window(game->mlx, game->player.image,
			game->player.x, game->player.y);
	}
	else
	{
		mlx_delete_image(game->mlx, game->player.image);
		xpm = mlx_load_xpm42("assets/player/sf1_b.xpm42");
		game->player.image = mlx_texture_to_image(game->mlx, &xpm->texture);
		mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
		mlx_image_to_window(game->mlx, game->player.image,
			game->player.x, game->player.y);
	}
	mlx_delete_xpm42(xpm);
}

void	exit_open(t_game *game)
{
	if (game->player.collected == game->map.collectibles)
	{
		if (game->map.exit_close_img)
			mlx_delete_image(game->mlx, game->map.exit_close_img);
		mlx_image_to_window(game->mlx, game->map.exit_open_img,
			game->map.exit_x * TILE_SIZE, game->map.exit_y * TILE_SIZE);
		game->map.exit_opened = true;
	}
}
