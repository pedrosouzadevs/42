/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:30:42 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 20:56:53 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	char	**map;

	map = NULL;
	map = parse_map(map, argc, argv);
	game.map.current_map = map;
	search_flood_fill(&game);
	setup_game(&game);
	render(&game, map);
	mlx_loop_hook(game.mlx_ptr, check_collectibles, &game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game.win_ptr, 17, 0, close_game_when_x_is_clicked, &game);
	mlx_loop(game.mlx_ptr);
	close_game(&game);
	free(map);
	return (0);
}
