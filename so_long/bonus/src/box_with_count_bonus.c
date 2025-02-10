/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_with_count_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:09:55 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/02/06 17:37:34 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	create_box(t_game *game)
{
	mlx_texture_t	*xpm;
	char			*count_str;

	if (game->map.box_img)
		mlx_delete_image(game->mlx, game->map.box_img);
	xpm = mlx_load_png("assets/box.png");
	if (!xpm)
		return ;
	game->map.box_img = mlx_texture_to_image(game->mlx, xpm);
	mlx_delete_texture(xpm);
	if (!game->map.box_img)
		return ;
	mlx_resize_image(game->map.box_img,
		(TILE_SIZE + TILE_SIZE), (TILE_SIZE - TILE_SIZE / 3));
	mlx_image_to_window(game->mlx, game->map.box_img,
		(game->map.width / 2 * TILE_SIZE - TILE_SIZE / 3), (TILE_SIZE / 5));
	mlx_put_string(game->mlx, "Count: ",
		(game->map.width / 2 * TILE_SIZE), (TILE_SIZE / 3));
	count_str = ft_itoa(game->player.count);
	if (!count_str)
		return ;
	mlx_put_string(game->mlx, count_str,
		(game->map.width / 2 * (TILE_SIZE + TILE_SIZE / 5)), (TILE_SIZE / 3));
	free(count_str);
}

void	update_box(t_game *game)
{
	mlx_texture_t	*xpm;
	char			*count_str;

	if (game->map.box_img)
		mlx_delete_image(game->mlx, game->map.box_img);
	xpm = mlx_load_png("assets/box.png");
	if (!xpm)
		return ;
	game->map.box_img = mlx_texture_to_image(game->mlx, xpm);
	mlx_delete_texture(xpm);
	if (!game->map.box_img)
		return ;
	mlx_resize_image(game->map.box_img, (TILE_SIZE + TILE_SIZE),
		(TILE_SIZE - TILE_SIZE / 3));
	mlx_image_to_window(game->mlx, game->map.box_img,
		(game->map.width / 2 * TILE_SIZE - TILE_SIZE / 3), (TILE_SIZE / 5));
	mlx_put_string(game->mlx, "Count: ",
		(game->map.width / 2 * TILE_SIZE), (TILE_SIZE / 3));
	count_str = ft_itoa(game->player.count);
	if (!count_str)
		return ;
	mlx_put_string(game->mlx, count_str,
		(game->map.width / 2 * (TILE_SIZE + TILE_SIZE / 5)), (TILE_SIZE / 3));
	free(count_str);
}
