/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_with_count_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:09:55 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/02/14 17:48:25 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	create_box(t_game *game)
{
	mlx_texture_t	*xpm;

	if (game->map.box_img)
		mlx_delete_image(game->mlx, game->map.box_img);
	xpm = mlx_load_png("assets/box.png");
	game->map.box_img = mlx_texture_to_image(game->mlx, xpm);
	mlx_delete_texture(xpm);
	mlx_resize_image(game->map.box_img, (TILE_SIZE + TILE_SIZE),
		(TILE_SIZE - TILE_SIZE / 3));
	mlx_image_to_window(game->mlx, game->map.box_img,
		(game->map.width / 2 * TILE_SIZE - TILE_SIZE / 3), (TILE_SIZE / 5));
	update_box_text(game);
}

void	update_box(t_game *game)
{
	mlx_texture_t	*xpm;

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
	update_box_text(game);
}

void	update_box_text(t_game *game)
{
	char	*count_str;
	char	*final_string;

	count_str = NULL;
	final_string = NULL;
	count_str = ft_itoa(game->player.count);
	if (!count_str)
		return ;
	final_string = ft_strjoin("Count:", count_str);
	if (!final_string)
		return ;
	if (!game->mlx)
		return ;
	if (game->player.count == 0)
		mlx_put_string(game->mlx, "Count:0",
			(game->map.width / 2 * TILE_SIZE), (TILE_SIZE / 3));
	else
		mlx_put_string(game->mlx, final_string,
			(game->map.width / 2 * TILE_SIZE), (TILE_SIZE / 3));
	free(final_string);
	free(count_str);
}
