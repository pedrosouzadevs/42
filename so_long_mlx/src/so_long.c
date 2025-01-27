/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*
 By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:56:09 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/24 15:40:15 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int is_wall(t_game *game, int x, int y)
{
    int map_x = x / TILE_SIZE;
    int map_y = y / TILE_SIZE;
    return (game->map.map[map_y][map_x] == '1');
}

int key_hook(int keycode, void *param)
{
   t_game *game = (t_game *)param;
   int new_x = game->player.x;
   int new_y = game->player.y;
   int can_jump = (game->player.y == game->player.initial_y ||
                  is_wall(game, game->player.x, game->player.y + TILE_SIZE));

   if (keycode == 65307)
       mlx_loop_end(game->mlx);
   else if (keycode == 100 && !is_wall(game, game->player.x + TILE_SIZE, game->player.y))
       new_x += 50;
   else if (keycode == 97 && !is_wall(game, game->player.x - TILE_SIZE, game->player.y))
       new_x -= 50;
   else if (keycode == 119 && !game->player.jump && can_jump)
   {
       game->player.jump = 1;
       game->player.initial_y = game->player.y;
   }
   else if (keycode == 115 && !is_wall(game, game->player.x, game->player.y + TILE_SIZE))
   {
       if (is_wall(game, game->player.x, game->player.y - TILE_SIZE))
       {
           new_y += TILE_SIZE;
           game->player.initial_y = new_y;
       }
   }

   if (game->player.jump)
   {
       int jump_distance = game->player.initial_y - game->player.y;
       if (jump_distance < JUMP_HEIGHT && !is_wall(game, game->player.x, game->player.y - JUMP_SPEED))
           new_y -= JUMP_SPEED;
       else
       {
           game->player.jump = 0;
           game->player.initial_y = new_y;
       }
   }
   else if (!is_wall(game, game->player.x, game->player.y + GRAVITY))
   {
       new_y += GRAVITY;
       if (is_wall(game, game->player.x, game->player.y + GRAVITY))
           game->player.initial_y = new_y;
   }

   game->player.x = new_x;
   game->player.y = new_y;

   mlx_clear_window(game->mlx, game->window);
   render_map(game);
   mlx_put_image_to_window(game->mlx, game->window, game->player.image, game->player.x, game->player.y);
   return (0);
}// int key_hook(int keycode, void *param)
// {
// 	t_game *game;

// 	game = (t_game *)param;
//     if (keycode == 65307)  // 'ESC' para sair
//         mlx_loop_end(game->mlx);
//     if (keycode == 100)  // seta direita
//         game->player.x += 50;
//     if (keycode == 97)  // seta esquerda
//         game->player.x -= 50;
//     if (keycode == 119)  // seta cima
//         game->player.y -= 50;
//     if (keycode == 115)  // seta baixo
//         game->player.y += 50;

//     mlx_clear_window(game->mlx, game->window);  // Limpa a tela
// 	render_map(game);  // Renderiza o mapa
// 	mlx_put_image_to_window(game->mlx, game->window, game->player.image, game->player.x, game->player.y);
//     return (0);
// }


int main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
	{
		write(2, "Use ./so_long mapa.ber\n", 27);
		return 1;
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		write(2, "Erro ao alocar memória\n", 23);
		return 1;
	}
	game->map.map = read_map(argv, game);
	game->player.jump = 0;
	if (!game->map.map)
	{
		write(2, "Erro ao ler o mapa\n", 20);
		return 1;
	}
	game->mlx = mlx_init();
    if (!game->mlx) {
        write(2, "Erro ao inicializar o MinilibX\n", 30);
		free(game);
        return 1;
    }
    game->window= mlx_new_window(game->mlx, (game->map.width * 100), (game->map.height * 100), "Meu Jogo 2D");
	if (!game->window)
	{
		write(2, "Erro ao criar a janela\n", 24);
		free(game);
		return 1;
	}
	init_images(game);
	verify_map(game);
	verify_wall(game);
	find_player_position(game);
	render_map(game);
	mlx_put_image_to_window(game->mlx, game->window, game->player.image, game->player.x, game->player.y);
    mlx_key_hook(game->window, key_hook, game);  // Passa o ponteiro da janela
    mlx_loop(game->mlx);  // Inicia o loop do MinilibX
	free_game_resources(game);
    return (0);
}
