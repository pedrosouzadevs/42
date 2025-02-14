/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:36:27 by pdro              #+#    #+#             */
/*   Updated: 2025/02/14 18:36:24 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	free_game_resources(t_game *game)
{
	free_images(game);
	if (game->window)
		mlx_delete_image(game->mlx, game->window);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_maps(game);
	free(game);
}

void	free_images(t_game *game)
{
	if (game->map.collectible_img)
		mlx_delete_image(game->mlx, game->map.collectible_img);
	if (game->map.exit_close_img)
		mlx_delete_image(game->mlx, game->map.exit_close_img);
	if (game->map.floor_img)
		mlx_delete_image(game->mlx, game->map.floor_img);
	if (game->player.image)
		mlx_delete_image(game->mlx, game->player.image);
	if (game->map.exit_open_img)
		mlx_delete_image(game->mlx, game->map.exit_open_img);
	if (game->map.wall_img)
		mlx_delete_image(game->mlx, game->map.wall_img);
	if (game->map.box_img)
		mlx_delete_image(game->mlx, game->map.box_img);
	if (game->enemy.image)
		mlx_delete_image(game->mlx, game->enemy.image);
}

void	error_none_player_exit_colec(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("Map must have at least one exit, ");
	ft_printf("one collectible and one player\n");
	free_game_resources(game);
	exit(EXIT_FAILURE);
}

void	is_map_retangle(t_game *game)
{
	if (game->map.width == game->map.height)
	{
		ft_printf("Error\nMap must be a rectangle\n");
		free_game_resources(game);
		exit(EXIT_FAILURE);
	}
}

void	exit_error(t_game *game)
{
	ft_printf("Error\nwrong map dimensions\n");
	free_game_resources(game);
	exit(EXIT_FAILURE);
}
