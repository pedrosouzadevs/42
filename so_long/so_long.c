// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <MLX42/MLX42.h>

#define WIDTH 1500
#define HEIGHT 800
#define JUMP_SPEED -1  // Velocidade para subir
#define GRAVITY 1      // Velocidade para descer
#define INITIAL_Y 730    // Posição inicial no eixo Y
#define JUMP_DISTANCE 50  // Distância máxima do salto

static mlx_image_t* image;
static bool is_moving_up = false;
static bool is_jump_enabled = true;
static int jump_start_y;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
    (void)param;
    for (uint32_t i = 0; i < image->width; ++i)
    {
        for (uint32_t y = 0; y < image->height; ++y)
        {
            uint32_t color = ft_pixel(
                rand() % 0xFF, // R
                rand() % 0xFF, // G
                rand() % 0xFF, // B
                rand() % 0xFF  // A
            );
            mlx_put_pixel(image, i, y, color);
        }
    }
}

void update_jump_position()
{
    if (is_moving_up)
    {
        image->instances[0].y += JUMP_SPEED;  // Subir
        if (image->instances[0].y <= jump_start_y - JUMP_DISTANCE)
        {
            is_moving_up = false;  // Parar quando atingir a distância máxima do salto
        }
    }
    else if (image->instances[0].y < INITIAL_Y)
    {
        image->instances[0].y += GRAVITY;  // Descer
        if (image->instances[0].y >= INITIAL_Y)
        {
            image->instances[0].y = INITIAL_Y;  // Evitar ultrapassar o chão
            is_jump_enabled = true;  // Habilitar nova subida
        }
    }
}

void ft_hook(void* param)
{
    mlx_t* mlx = param;

    if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);

    // Movimento lateral
    if (mlx_is_key_down(mlx, MLX_KEY_A))
        image->instances[0].x -= 2;
    if (mlx_is_key_down(mlx, MLX_KEY_D))
        image->instances[0].x += 2;

    // Movimento vertical (salto)
    if (mlx_is_key_down(mlx, MLX_KEY_W) && is_jump_enabled)
    {
        is_moving_up = true;
        is_jump_enabled = false;  // Impedir novo salto até retorno ao chão
        jump_start_y = image->instances[0].y;  // Registrar a posição inicial do salto
    }

    update_jump_position();
}

// -----------------------------------------------------------------------------

int32_t main(void)
{
    mlx_t* mlx;

    if (!(mlx = mlx_init(WIDTH, HEIGHT, "so_long", true)))
    {
        puts(mlx_strerror(mlx_errno));
        return(EXIT_FAILURE);
    }
    if (!(image = mlx_new_image(mlx, 40, 70)))
    {
        mlx_close_window(mlx);
        puts(mlx_strerror(mlx_errno));
        return(EXIT_FAILURE);
    }
    if (mlx_image_to_window(mlx, image, 750, INITIAL_Y) == -1)
    {
        mlx_close_window(mlx);
        puts(mlx_strerror(mlx_errno));
        return(EXIT_FAILURE);
    }

    mlx_loop_hook(mlx, ft_randomize, mlx);
    mlx_loop_hook(mlx, ft_hook, mlx);

    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <unistd.h>
// #include <MLX42/MLX42.h>

// #define WIDTH 1500
// #define HEIGHT 800

// static mlx_image_t* image;

// // -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_W))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_S))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_A))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_D))
// 		image->instances[0].x += 5;
// }

// // -----------------------------------------------------------------------------

// int32_t main(void)
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 40, 70)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}

// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
