/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:49:18 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 20:07:54 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	background_entire_screen_put(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j] && j < count_rows(map))
	{
		i = 0;
		while (map[j][i] && i < count_columns(map))
		{
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, game->background.background_ptr,
				i * WALL_SIZE, j * WALL_SIZE);
			i++;
		}
		j++;
	}
	return (0);
}

int	background_specific_position_put(t_game *game, int row, int column)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->background.background_ptr,
		row * WALL_SIZE, column * WALL_SIZE);
	return (0);
}
