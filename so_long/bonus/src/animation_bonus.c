/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:06:53 by pdro              #+#    #+#             */
/*   Updated: 2025/02/04 14:37:03 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void animate_player(t_game *game)
{
    xpm_t	*xpm;
    int		frame;

	frame = game->player.animation_frame % 3;
    mlx_delete_image(game->mlx, game->player.image);

    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
        if (frame == 0)
            xpm = mlx_load_xpm42("assets/player/sr1_b.xpm42");
        else if (frame == 1)
            xpm = mlx_load_xpm42("assets/player/sr2_b.xpm42");
        else
            xpm = mlx_load_xpm42("assets/player/sr3_b.xpm42");
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
        if (frame == 0)
            xpm = mlx_load_xpm42("assets/player/sl1_b.xpm42");
        else if (frame == 1)
            xpm = mlx_load_xpm42("assets/player/sl2_b.xpm42");
        else
            xpm = mlx_load_xpm42("assets/player/sl3_b.xpm42");
    }
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		if (frame == 0)
			xpm = mlx_load_xpm42("assets/player/su1_b.xpm42");
		else if (frame == 1)
			xpm = mlx_load_xpm42("assets/player/su2_b.xpm42");
		else
			xpm = mlx_load_xpm42("assets/player/su3_b.xpm42");
	}
    else
	{
        if (frame == 0)
            xpm = mlx_load_xpm42("assets/player/sf1_b.xpm42");
        else if (frame == 1)
            xpm = mlx_load_xpm42("assets/player/sf2_b.xpm42");
        else
            xpm = mlx_load_xpm42("assets/player/sf3_b.xpm42"); // Imagem estática
    }

    game->player.image = mlx_texture_to_image(game->mlx, &xpm->texture);
    mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
    mlx_image_to_window(game->mlx, game->player.image, game->player.x, game->player.y);
    mlx_delete_xpm42(xpm);
    game->player.animation_frame++;
}
void animate_player_evolution(t_game *game)
{
    xpm_t	*xpm;
    int		frame;

	frame = game->player.animation_frame % 3;
    mlx_delete_image(game->mlx, game->player.image);

    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
        if (frame == 0)
            xpm = mlx_load_xpm42("assets/player/wr1_b.xpm42");
        else if (frame == 1)
            xpm = mlx_load_xpm42("assets/player/wr2_b.xpm42");
        else
            xpm = mlx_load_xpm42("assets/player/wr3_b.xpm42");
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
        if (frame == 0)
            xpm = mlx_load_xpm42("assets/player/wl1_b.xpm42");
        else if (frame == 1)
            xpm = mlx_load_xpm42("assets/player/wl2_b.xpm42");
        else
            xpm = mlx_load_xpm42("assets/player/wl3_b.xpm42");
    }
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		if (frame == 0)
			xpm = mlx_load_xpm42("assets/player/wu1_b.xpm42");
		else if (frame == 1)
			xpm = mlx_load_xpm42("assets/player/wu2_b.xpm42");
		else
			xpm = mlx_load_xpm42("assets/player/wu3_b.xpm42");
	}
    else
	{
        if (frame == 0)
            xpm = mlx_load_xpm42("assets/player/wb1_b.xpm42");
        else if (frame == 1)
            xpm = mlx_load_xpm42("assets/player/wb2_b.xpm42");
        else
            xpm = mlx_load_xpm42("assets/player/wb3_b.xpm42"); // Imagem estática
    }

    game->player.image = mlx_texture_to_image(game->mlx, &xpm->texture);
    mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
    mlx_image_to_window(game->mlx, game->player.image, game->player.x, game->player.y);
    mlx_delete_xpm42(xpm);
    game->player.animation_frame++;
}
