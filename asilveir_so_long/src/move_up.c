/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:08:16 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 22:56:12 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	move_player_up(t_game *game, int row, int column)
{
	game->map.current_map[row][column] = '0';
	put_background_down(game, column, row - 1);
	alternate_char_animation_up(game, column, row - 1);
	game->map.current_map[row - 1][column] = 'P';
	if (game->map.current_map[row - 1][column + 1] == 'C')
		game->map.current_map[row - 1][column + 1] = '0';
	print_number_of_movements();
	return (0);
}

int	try_move_up(t_game *game, int row, int column)
{
	if (row < 2)
		return (1);
	if (ft_strcmp(game->door.location,
			"resources/map/locked_exit_32.xpm") == 0)
	{
		if (game->map.current_map[row - 1][column] != '1' &&
				game->map.current_map[row - 1][column] != 'E')
			move_player_up(game, row, column);
		return (1);
	}
	if (game->map.current_map[row - 1][column] == 'E')
		close_game(game);
	if (game->map.current_map[row - 1][column] != '1')
		move_player_up(game, row, column);
	return (0);
}
