/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:15:36 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/02/11 16:39:59 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	init_animation_d(t_game *game, int frame)
{
	xpm_t		*xpm;
	mlx_image_t	*new_image;

	if (frame == 0)
		xpm = mlx_load_xpm42("assets/player/sr1_b.xpm42");
	else if (frame == 1)
		xpm = mlx_load_xpm42("assets/player/sr2_b.xpm42");
	else
		xpm = mlx_load_xpm42("assets/player/sr3_b.xpm42");
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

void	init_animation_a(t_game *game, int frame)
{
	xpm_t		*xpm;
	mlx_image_t	*new_image;

	if (frame == 0)
		xpm = mlx_load_xpm42("assets/player/sl1_b.xpm42");
	else if (frame == 1)
		xpm = mlx_load_xpm42("assets/player/sl2_b.xpm42");
	else
		xpm = mlx_load_xpm42("assets/player/sl3_b.xpm42");
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

void	init_animation_s(t_game *game, int frame)
{
	xpm_t		*xpm;
	mlx_image_t	*new_image;

	if (frame == 0)
		xpm = mlx_load_xpm42("assets/player/sf1_b.xpm42");
	else if (frame == 1)
		xpm = mlx_load_xpm42("assets/player/sf2_b.xpm42");
	else
		xpm = mlx_load_xpm42("assets/player/sf3_b.xpm42");
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

void	init_animation_w(t_game *game, int frame)
{
	xpm_t		*xpm;
	mlx_image_t	*new_image;

	if (frame == 0)
		xpm = mlx_load_xpm42("assets/player/su1_b.xpm42");
	else if (frame == 1)
		xpm = mlx_load_xpm42("assets/player/su2_b.xpm42");
	else
		xpm = mlx_load_xpm42("assets/player/su3_b.xpm42");
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
