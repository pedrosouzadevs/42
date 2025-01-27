/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:38:44 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/27 16:42:06 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libs/libft/libft.h"

typedef struct s_player
{
	void *image;
	int x;
	int y;
	int jump;
	int initial_y;
} t_player;

typedef struct s_map
{
	char **map;
	int width;
	int height;
	int player;
	int collectibles;
	int exit;
	int enemies;
	void *wall_img;
	void *collectible_img;
	void *exit_img;
	void *enemy_img;
	void *floor_img;
} t_map;

typedef struct s_game
{
	void *mlx;
	void *window;
	t_player player;
	t_map map;
} t_game;

#define TILE_SIZE 100
#define JUMP_SPEED 25  // Velocidade para subir
#define GRAVITY 25      // Velocidade para descer
#define JUMP_HEIGHT 150  // Distância máxima do salto
#define JUMP_DISTANCE 50  // Distância máxima do salto
static bool is_moving_up;
static bool is_jump_enabled;
static bool is_moving_down;


char **read_map(char **argv, t_game *game);
void exit_error(void);
int ft_count_lines(int fd);
void init_images(t_game *game);
void render_map(t_game *game);
int	ft_line_length(int fd);
void free_game_resources(t_game *game);
void	verify_wall(t_game *game);
void	verify_map(t_game *game);
void	find_player_position(t_game *game);
void	error_wall(void);
void	error_none_player_exit_colec(void);

#endif
