/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:44:33 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 20:57:10 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->door.door_ptr);
	mlx_destroy_image(game->mlx_ptr, game->collectible.collectible_ptr);
	mlx_destroy_image(game->mlx_ptr, game->background.background_ptr);
	mlx_destroy_image(game->mlx_ptr, game->character.character_ptr);
	mlx_destroy_image(game->mlx_ptr, game->wall.wall_ptr);
	mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	if (game->map.current_map)
		free_map(game->map.current_map);
	exit (0);
	return (0);
}

void	free_character_frames(void *frames[2], void *mlx_ptr)
{
	if (frames[0])
	{
		mlx_destroy_image(mlx_ptr, frames[0]);
		frames[0] = NULL;
	}
	if (frames[1])
	{
		mlx_destroy_image(mlx_ptr, frames[1]);
		frames[1] = NULL;
	}
}

int	close_game_when_x_is_clicked(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	close_game(game);
	return (0);
}
