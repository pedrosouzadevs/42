/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation_evol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:13:33 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/02/11 16:39:15 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	init_evol_w(t_game *game, int frame)
{
	xpm_t		*xpm;
	mlx_image_t	*new_image;

	if (frame == 0)
		xpm = mlx_load_xpm42("assets/player/wu1_b.xpm42");
	else if (frame == 1)
		xpm = mlx_load_xpm42("assets/player/wu2_b.xpm42");
	else
		xpm = mlx_load_xpm42("assets/player/wu3_b.xpm42");
	if (!xpm)
	{
		ft_printf("Error\nLoading xpm\n");
		return ;
	}
	new_image = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	if (!new_image)
	{
		ft_printf("Error\nConverting texture to image\n");
		return ;
	}
	game->player.image = new_image;
	mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
}

void	init_evol_a(t_game *game, int frame)
{
	xpm_t		*xpm;
	mlx_image_t	*new_image;

	if (frame == 0)
		xpm = mlx_load_xpm42("assets/player/wl1_b.xpm42");
	else if (frame == 1)
		xpm = mlx_load_xpm42("assets/player/wl2_b.xpm42");
	else
		xpm = mlx_load_xpm42("assets/player/wl3_b.xpm42");
	if (!xpm)
	{
		ft_printf("Error\nLoading xpm\n");
		return ;
	}
	new_image = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	if (!new_image)
	{
		ft_printf("Error\nConverting texture to image\n");
		return ;
	}
	game->player.image = new_image;
	mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
}

void	init_evol_s(t_game *game, int frame)
{
	xpm_t		*xpm;
	mlx_image_t	*new_image;

	if (frame == 0)
		xpm = mlx_load_xpm42("assets/player/wb1_b.xpm42");
	else if (frame == 1)
		xpm = mlx_load_xpm42("assets/player/wb2_b.xpm42");
	else
		xpm = mlx_load_xpm42("assets/player/wb3_b.xpm42");
	if (!xpm)
	{
		ft_printf("Error\nLoading xpm\n");
		return ;
	}
	new_image = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	if (!new_image)
	{
		ft_printf("Error\nConverting texture to image\n");
		return ;
	}
	game->player.image = new_image;
	mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
}

void	init_evol_d(t_game *game, int frame)
{
	xpm_t		*xpm;
	mlx_image_t	*new_image;

	if (frame == 0)
		xpm = mlx_load_xpm42("assets/player/wr1_b.xpm42");
	else if (frame == 1)
		xpm = mlx_load_xpm42("assets/player/wr2_b.xpm42");
	else
		xpm = mlx_load_xpm42("assets/player/wr3_b.xpm42");
	if (!xpm)
	{
		ft_printf("Error\nLoading xpm\n");
		return ;
	}
	new_image = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	if (!new_image)
	{
		ft_printf("Error\nConverting texture to image\n");
		return ;
	}
	game->player.image = new_image;
	mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
}
