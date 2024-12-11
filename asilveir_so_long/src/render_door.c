/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:18:41 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 20:32:09 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

void	render_door(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->door.door_ptr,
		x * WALL_SIZE, y * WALL_SIZE);
}

int	replace_door(t_game *game, int i, int j)
{
	mlx_destroy_image(game->mlx_ptr, game->door.door_ptr);
	game->door.door_ptr = NULL;
	game->door.door_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"resources/map/unlocked_exit_32.xpm",
			&game->wall.width, &game->wall.height);
	game->door.location = "resources/map/unlocked_exit_32.xpm";
	render_door(game, i, j);
	return (0);
}

int	render_unlocked_door(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (rows_of_map_exist(game, j))
	{
		i = 0;
		while (current_row_exists(game, j, i))
		{
			if (found_door_position(game, j, i))
			{
				if ((ft_strcmp(game->door.location,
							"resources/map/locked_exit_32.xpm") == 0))
					return (replace_door(game, i, j));
			}
			i++;
		}
		j++;
	}
	return (0);
}
