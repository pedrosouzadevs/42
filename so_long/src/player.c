/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdro <pdro@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 17:38:34 by pdro              #+#    #+#             */
/*   Updated: 2025-02-03 17:38:34 by pdro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	refresh_player(t_game *game)
{
	xpm_t	*xpm;

	if (game->player.collected == game->map.collectibles)
	{
		mlx_delete_image(game->mlx, game->player.image);
		xpm = mlx_load_xpm42("assets/player/war_b.xpm42");
		game->player.image = mlx_texture_to_image(game->mlx, &xpm->texture);
		mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
		mlx_image_to_window(game->mlx, game->player.image,
			game->player.x, game->player.y);
	}
	else
	{
		mlx_delete_image(game->mlx, game->player.image);
		// animate_player(game);
		xpm = mlx_load_xpm42("assets/player/sf1_b.xpm42");
		game->player.image = mlx_texture_to_image(game->mlx, &xpm->texture);
		mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE);
		mlx_image_to_window(game->mlx, game->player.image,
			game->player.x, game->player.y);
	}
}
// void animate_player(t_game *game)
// {
//     xpm_t *xpm;
//     int frame;
//     double current_time;
//     static double last_update = 0;
//     const double ANIMATION_INTERVAL = 0.1;

//     current_time = mlx_get_time();

//     if (current_time - last_update >= ANIMATION_INTERVAL)
//     {
//         frame = game->player.animation_frame;

//         // Só deleta se a imagem existir
//         if (game->player.image != NULL)
//             mlx_delete_image(game->mlx, game->player.image);
//         game->player.image = NULL;  // Importante zerar após deletar

//         // Carregar nova imagem
//         if (mlx_is_key_down(game->mlx, MLX_KEY_D)) {
//             if (frame == 0)
//                 xpm = mlx_load_xpm42("assets/player/sr1_b.xpm42");
//             else if (frame == 1)
//                 xpm = mlx_load_xpm42("assets/player/sr3_b.xpm42");
//             else
//                 xpm = mlx_load_xpm42("assets/player/sr2_b.xpm42");

//             game->player.animation_frame = (frame + 1) % 3;
//         }
//         else if (mlx_is_key_down(game->mlx, MLX_KEY_A)) {
//             if (frame == 0)
//                 xpm = mlx_load_xpm42("assets/player/sl1_b.xpm42");
//             else if (frame == 1)
//                 xpm = mlx_load_xpm42("assets/player/sl2_b.xpm42");
//             else
//                 xpm = mlx_load_xpm42("assets/player/sl3_b.xpm42");

//             game->player.animation_frame = (frame + 1) % 3;
//         }
//         else {
//             xpm = mlx_load_xpm42("assets/player/sf1_b.xpm42");
//             game->player.animation_frame = 0;
//         }

//         // Verificar se o XPM foi carregado com sucesso
//         if (!xpm)
//             return;

//         // Criar nova imagem
//         game->player.image = mlx_texture_to_image(game->mlx, &xpm->texture);
//         if (!game->player.image)
//         {
//             mlx_delete_xpm42(xpm);
//             return;
//         }

//         // Redimensionar e colocar na janela
//         if (mlx_resize_image(game->player.image, TILE_SIZE, TILE_SIZE) == 0)
//         {
//             if (mlx_image_to_window(game->mlx, game->player.image,
//                                   game->player.x, game->player.y) < 0)
//             {
//                 mlx_delete_image(game->mlx, game->player.image);
//                 game->player.image = NULL;
//             }
//         }

//         // Liberar XPM após uso
//         mlx_delete_xpm42(xpm);
//         last_update = current_time;
//     }
// }
void	exit_open(t_game *game)
{
	if (game->player.collected == game->map.collectibles)
	{
		if (game->map.exit_close_img)
			mlx_delete_image(game->mlx, game->map.exit_close_img);
		mlx_image_to_window(game->mlx, game->map.exit_open_img,
			game->map.exit_x * TILE_SIZE, game->map.exit_y * TILE_SIZE);
		game->map.exit_opened = true;
	}
}
