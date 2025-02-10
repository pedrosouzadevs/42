/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:06:53 by pdro              #+#    #+#             */
/*   Updated: 2025/02/10 16:07:41 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	animate_player(t_game *game)
{
	int		frame;

	frame = game->player.animation_frame % 3;
	if (game->player.image)
		mlx_delete_image(game->mlx, game->player.image);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		init_animation_d(game, frame);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		init_animation_a(game, frame);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		init_animation_w(game, frame);
	else
		init_animation_s(game, frame);
	mlx_image_to_window(game->mlx, game->player.image,
		game->player.x, game->player.y);
	game->player.animation_frame++;
}

void	animate_player_evolution(t_game *game)
{
	int		frame;

	frame = game->player.animation_frame % 3;
	if (game->player.image)
		mlx_delete_image(game->mlx, game->player.image);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		init_evol_d(game, frame);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		init_evol_a(game, frame);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		init_evol_w(game, frame);
	else
		init_evol_s(game, frame);
	mlx_image_to_window(game->mlx, game->player.image,
		game->player.x, game->player.y);
	game->player.animation_frame++;
}
