/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:05:36 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/09 16:19:47 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	count_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	return (rows);
}

int	check_if_map_is_rectangular(char **map)
{
	int	row_length;
	int	j;

	if (!map || !map[0])
		return (1);
	row_length = ft_strlen(map[0]);
	j = 1;
	while (map[j])
	{
		if (j == count_rows(map) - 1)
			row_length--;
		if ((int)ft_strlen(map[j]) != row_length)
		{
			write(1, "Error\nMap is not rectangular!\n", 30);
			free_map(map);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	return (0);
}

int	search_walls_horizontally(char **map)
{
	int	i;
	int	height;

	i = 0;
	height = count_rows(map) - 1;
	while (map[0][i] && map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map[height][i] && map[height][i] != '\n')
	{
		if (map[height][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	search_walls_vertically(char **map)
{
	int	i;
	int	width;

	i = 0;
	if (!map)
		return (1);
	width = ft_strlen(map[0]) - 2;
	while (i < count_rows(map) && map[i][0])
	{
		if (map[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < count_rows(map) && map[i][width])
	{
		if (map[i][width] != '1' )
			return (1);
		i++;
	}
	return (0);
}

int	map_is_surrounded_by_walls(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!map)
		return (1);
	if (search_walls_horizontally(map) == 1
		|| search_walls_vertically(map) == 1)
	{
		write(1, "Error!\nMap is not surrounded by walls!\n", 39);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	return (0);
}
