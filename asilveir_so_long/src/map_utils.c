/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:28:05 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 20:06:52 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	rows_of_map_exist(t_game *game, int row_number)
{
	if (game->map.current_map[row_number])
		return (1);
	return (0);
}

int	current_row_exists(t_game *game, int row_number, int column_number)
{
	if (game->map.current_map[row_number][column_number])
		return (1);
	return (0);
}

int	found_character_position(t_game *game, int row_number, int column_number)
{
	if (game->map.current_map[row_number][column_number] == 'P')
		return (1);
	return (0);
}

int	found_door_position(t_game *game, int row_number, int column_number)
{
	if (game->map.current_map[row_number][column_number] == 'E')
		return (1);
	return (0);
}
