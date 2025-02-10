/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:38:57 by pdro              #+#    #+#             */
/*   Updated: 2025/02/10 16:18:21 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game_resources(t_game *game)
{
	int	i;

	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map.map)
	{
		i = 0;
		while (game->map.map[i])
		{
			free(game->map.map[i]);
			i++;
		}
		free(game->map.map);
	}
	if (game->map.map_route)
	{
		i = 0;
		while (game->map.map_route[i])
			free(game->map.map_route[i++]);
		free(game->map.map_route);
	}
	free(game);
}

void	error_wall(void)
{
	printf("Error\nMap must have walls on the edges\n");
	exit(EXIT_FAILURE);
}

void	error_none_player_exit_colec(void)
{
	printf("Error\n");
	printf("Map must have at least one exit, one collectible and one player\n");
	exit(EXIT_FAILURE);
}

void	is_map_retangle(t_game *game)
{
	if (game->map.width == game->map.height)
	{
		printf("Error\nMap must be a rectangle\n");
		exit(EXIT_FAILURE);
	}
}

void	exit_error(void)
{
	printf("Error\nwrong map dimensions\n");
	exit(EXIT_FAILURE);
}
