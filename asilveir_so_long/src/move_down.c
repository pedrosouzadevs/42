/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:11:45 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 22:54:22 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

void	print_number_of_movements(void)
{
	char	*number_of_mvs;

	g_number_of_movements++;
	number_of_mvs = ft_itoa(g_number_of_movements);
	write(1, "Movements: ", 11);
	write(1, number_of_mvs, ft_strlen(number_of_mvs));
	write(1, "\n", 1);
	free(number_of_mvs);
}

int	move_player_down(t_game *game, int row, int column)
{
	game->map.current_map[row][column] = '0';
	put_background_up(game, column, row + 2, game->map.current_map);
	alternate_char_animation_down(game, column, row + 1);
	game->map.current_map[row + 1][column] = 'P';
	if (game->map.current_map[row + 1][column + 1] == 'C')
		game->map.current_map[row + 1][column + 1] = '0';
	if (game->map.current_map[row + 1][column] == 'C')
		game->map.current_map[row + 1][column] = '0';
	print_number_of_movements();
	return (0);
}

int	try_move_down(t_game *game, int row, int column)
{
	if (ft_strcmp(game->door.location,
			"resources/map/locked_exit_32.xpm") == 0)
	{
		if (game->map.current_map[row + 1][column] != '1'
			&& game->map.current_map[row + 1][column] != 'E')
			move_player_down(game, row, column);
		return (1);
	}
	if (game->map.current_map[row + 1][column] == 'E')
		close_game(game);
	if (game->map.current_map[row + 1][column] != '1')
		move_player_down(game, row, column);
	return (0);
}
