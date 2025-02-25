/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:47:22 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/02/14 18:34:30 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	error_width_map(t_game *game)
{
	ft_printf("Error\nMap must have the same width in all lines\n");
	free_game_resources(game);
	exit(EXIT_FAILURE);
}

void	error_more_player_exit(t_game *game)
{
	ft_printf("Error\nMap must have no more than one exit and one player\n");
	free_game_resources(game);
	exit(EXIT_FAILURE);
}

void	error_wall(t_game *game)
{
	ft_printf("Error\nMap must have walls on the edges\n");
	free_game_resources(game);
	exit(EXIT_FAILURE);
}

void	error_map_route(t_game *game)
{
	if (!game->map.map_route)
	{
		ft_printf("Error\nInvalid map_path/map\n");
		free_game_resources(game);
		exit(EXIT_FAILURE);
	}
}

void	free_maps(t_game *game)
{
	int	i;

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
}
