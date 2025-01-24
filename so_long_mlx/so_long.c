/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:56:09 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/24 15:40:15 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#define WIDTH 1500
#define HEIGHT 800
#define JUMP_SPEED -2  // Velocidade para subir
#define GRAVITY 2      // Velocidade para descer
#define INITIAL_Y 730    // Posição inicial no eixo Y
#define JUMP_DISTANCE 50  // Distância máxima do salto

// static bool is_moving_up = false;
// static bool is_jump_enabled = true;
// static int jump_start_y;

// -----------------------------------------------------------------------------


// void update_jump_position()
// {
//     if (is_moving_up)
//     {
//         image->instances[0].y += JUMP_SPEED;  // Subir
//         if (image->instances[0].y <= jump_start_y - JUMP_DISTANCE)
//         {
//             is_moving_up = false;  // Parar quando atingir a distância máxima do salto
//         }
//     }
//     else if (image->instances[0].y < INITIAL_Y)
//     {
//         image->instances[0].y += GRAVITY;  // Descer
//         if (image->instances[0].y >= INITIAL_Y)
//         {
//             image->instances[0].y = INITIAL_Y;  // Evitar ultrapassar o chão
//             is_jump_enabled = true;  // Habilitar nova subida
//         }
//     }
// }

// void ft_hook(void* param)
// {
//     mlx_t* mlx = param;

//     if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
//         mlx_close_window(mlx);

//     // Movimento lateral
//     if (mlx_is_key_down(mlx, MLX_KEY_A))
//         image->instances[0].x -= 2;
//     if (mlx_is_key_down(mlx, MLX_KEY_D))
//         image->instances[0].x += 2;

//     // Movimento vertical (salto)
//     if (mlx_is_key_down(mlx, MLX_KEY_W) && is_jump_enabled)
//     {
//         is_moving_up = true;
//         is_jump_enabled = false;  // Impedir novo salto até retorno ao chão
//         jump_start_y = image->instances[0].y;  // Registrar a posição inicial do salto
//     }

//     update_jump_position();
// }

// -----------------------------------------------------------------------------

#include <mlx.h>

// int	close_window(int keycode, void *param)
// {
// 	if (keycode == 65307) // Código da tecla ESC
// 		mlx_loop_end(param); // Encerra o loop da MiniLibX
// 	return (0);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1000, 800, "So_long");
// 	mlx_clear_window(mlx, mlx_win); // Limpa a tela
//     mlx_string_put(mlx, mlx_win, 350, 280, 0xFFFFFF, "Bem-vindo ao jogo!");
// 	mlx_key_hook(mlx_win, close_window, mlx); // Define o hook para a tecla
// 	mlx_loop(mlx);
// }

void *mlx;
void *window;
void *player_image;
int player_x = 400;
int player_y = 300;

int key_hook(int keycode, void *param)
{
	(void) param;
    if (keycode == 65307)  // 'ESC' para sair
        mlx_loop_end(mlx);
    // if (keycode == 124)  // seta direita
    //     player_x += 10;
    // if (keycode == 123)  // seta esquerda
    //     player_x -= 10;
    // if (keycode == 126)  // seta cima
    //     player_y -= 10;
    // if (keycode == 125)  // seta baixo
    //     player_y += 10;

    mlx_clear_window(mlx, window);  // Limpa a tela
    return (0);
}

int main()
{
    mlx = mlx_init();
    if (!mlx) {
        write(2, "Erro ao inicializar o MinilibX\n", 30);
        return 1;
    }

    window = mlx_new_window(mlx, 800, 600, "Meu Jogo 2D");

    // Carregar a imagem XPM
    player_image = mlx_xpm_file_to_image(mlx, "assets/bulba.xpm", player_x, player_y);
    if (!player_image) {
        write(2, "Erro ao carregar a imagem (verifique o caminho e o formato da imagem)\n", 70);
        return 1;
    }

    mlx_put_image_to_window(mlx, window, player_image, player_x, player_y);  // Desenha a imagem
    mlx_key_hook(window, key_hook, window);  // Passa o ponteiro da janela
    mlx_loop(mlx);  // Inicia o loop do MinilibX
    return 0;
}
