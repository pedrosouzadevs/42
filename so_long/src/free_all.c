/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:12:32 by pdro              #+#    #+#             */
/*   Updated: 2025/01/27 15:34:31 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_game_resources(t_game *game)
{
	if (game->mlx) mlx_terminate(game->mlx);
	free(game);
}
