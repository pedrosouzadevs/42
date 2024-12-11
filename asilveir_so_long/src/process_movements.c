/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:51:50 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 20:12:27 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	door_is_locked(t_game *game)
{
	return (ft_strcmp(game->door.location,
			"resources/map/locked_door_48.xpm") == 0);
}

int	process_left_input(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (rows_of_map_exist(game, j))
	{
		i = 0;
		while (current_row_exists(game, j, i))
		{
			if (found_character_position(game, j, i))
				try_move_left(game, j, i);
			i++;
		}
		j++;
	}
	return (0);
}

int	process_right_input(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (rows_of_map_exist(game, j))
	{
		i = 0;
		while (current_row_exists(game, j, i))
		{
			if (found_character_position(game, j, i))
				return (try_move_right(game, j, i));
			i++;
		}
		j++;
	}
	return (0);
}

int	process_up_input(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (rows_of_map_exist(game, j))
	{
		i = 0;
		while (current_row_exists(game, j, i))
		{
			if (found_character_position(game, j, i))
				try_move_up(game, j, i);
			i++;
		}
		j++;
	}
	return (0);
}

int	process_down_input(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (rows_of_map_exist(game, j))
	{
		i = 0;
		while (current_row_exists(game, j, i))
		{
			if (found_character_position(game, j, i))
				return (try_move_down(game, j, i));
			i++;
		}
		j++;
	}
	return (0);
}
