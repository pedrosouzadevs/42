/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:36:27 by pdro              #+#    #+#             */
/*   Updated: 2025/02/11 16:40:21 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	free_game_resources(t_game *game)
{
	int	i;

	if (game->map.map)
	{
		i = 0;
		while (game->map.map[i])
			free(game->map.map[i++]);
		free(game->map.map);
	}
	if (game->map.map_route)
	{
		i = 0;
		while (game->map.map_route[i])
			free(game->map.map_route[i++]);
		free(game->map.map_route);
	}
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}

void	error_wall(void)
{
	ft_printf("Error\nMap must have walls on the edges\n");
	exit(EXIT_FAILURE);
}

void	error_none_player_exit_colec(void)
{
	ft_printf("Error\n");
	ft_printf("Map must have at least one exit, ");
	ft_printf("one collectible and one player\n");
	exit(EXIT_FAILURE);
}

void	is_map_retangle(t_game *game)
{
	if (game->map.width == game->map.height)
	{
		ft_printf("Error\nMap must be a rectangle\n");
		exit(EXIT_FAILURE);
	}
}

void	exit_error(void)
{
	ft_printf("Error\nwrong map dimensions\n");
	exit(EXIT_FAILURE);
}
