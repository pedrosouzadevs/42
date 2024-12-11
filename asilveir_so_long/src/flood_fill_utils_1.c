/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:16:15 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 20:07:43 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	count_columns(char **map)
{
	int	columns;

	if (!map || !map[0])
		return (0);
	columns = 0;
	while (map[0][columns])
		columns++;
	return (columns);
}

void	dfs(char **map, int current_row, int current_column, char new_char)
{
	int	rows_number;
	int	columns_number;

	rows_number = count_rows(map);
	columns_number = count_columns(map) - 1;
	if (current_row < 0 || current_row >= rows_number
		|| current_column < 0 || current_column >= columns_number
		|| (map[current_row][current_column] != 'P'
		&& map[current_row][current_column] != '0'
		&& map[current_row][current_column] != 'C'
		&& map[current_row][current_column] != 'E'))
		return ;
	map[current_row][current_column] = new_char;
	dfs(map, current_row + 1, current_column, new_char);
	dfs(map, current_row - 1, current_column, new_char);
	dfs(map, current_row, current_column + 1, new_char);
	dfs(map, current_row, current_column - 1, new_char);
}

void	flood_fill(char **map, int current_row,
		int current_column, char new_char)
{
	char	old_char;

	old_char = map[current_row][current_column];
	if (old_char == new_char || old_char == '1')
		return ;
	dfs(map, current_row, current_column, new_char);
}
