/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:22:00 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/09 16:20:38 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	only_one_exit(char **map)
{
	int	i;
	int	j;
	int	number_of_exits;

	j = 0;
	number_of_exits = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				number_of_exits++;
			i++;
		}
		j++;
	}
	if (number_of_exits > 1)
	{
		write(1, "Error\nMore than one exit found in the map", 41);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	return (0);
}
