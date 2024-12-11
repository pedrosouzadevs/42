/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:01:33 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 20:19:08 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

char	**copy_map(char **original)
{
	int		i;
	int		rows;
	char	**copy;

	rows = 0;
	while (original[rows])
		rows++;
	copy = malloc((rows + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[rows] = NULL;
	return (copy);
}

int	check_if_win_is_possible(char **map_copy)
{
	int	i;
	int	j;

	j = 0;
	while (map_copy[j])
	{
		i = 0;
		while (map_copy[j][i])
		{
			if (map_copy[j][i] == 'C' || map_copy[j][i] == 'E')
			{
				write(1, "Error\nIt's impossible to win!", 29);
				free_map(map_copy);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	search_flood_fill(t_game *game)
{
	int		i;
	int		j;
	char	**map_copy;

	map_copy = copy_map(game->map.current_map);
	if (!map_copy)
	{
		write(1, "Error\nFailed to allocate memory for map copy!", 45);
		exit(EXIT_FAILURE);
	}
	j = 0;
	while (map_copy[j])
	{
		i = 0;
		while (map_copy[j][i])
		{
			if (map_copy[j][i] == 'P')
				flood_fill(map_copy, j, i, 'X');
			i++;
		}
		j++;
	}
	check_if_win_is_possible(map_copy);
	free_map(map_copy);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
