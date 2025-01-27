/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdro <pdro@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 20:12:32 by pdro              #+#    #+#             */
/*   Updated: 2025-01-26 20:12:32 by pdro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_game_resources(t_game *game) {
    // Liberar imagens
    if (game->map.wall_img) mlx_destroy_image(game->mlx, game->map.wall_img);
    if (game->map.floor_img) mlx_destroy_image(game->mlx, game->map.floor_img);
    if (game->player.image) mlx_destroy_image(game->mlx, game->player.image);

    // Liberar mapa
    if (game->map.map) {
        for (int i = 0; game->map.map[i]; i++) {
            free(game->map.map[i]);
        }
        free(game->map.map);
    }

    // Liberar janela e conexão MLX
    if (game->window) mlx_destroy_window(game->mlx, game->window);
    if (game->mlx) mlx_destroy_display(game->mlx);

    free(game);
}
