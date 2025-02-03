/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdro <pdro@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 17:36:27 by pdro              #+#    #+#             */
/*   Updated: 2025-02-03 17:36:27 by pdro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	free_game_resources(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
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
