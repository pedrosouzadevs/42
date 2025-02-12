/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:38:44 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/02/12 17:29:43 by pedro-hm         ###   ########.fr       */
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
	void	*image;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	int		dist_traveled;
	int		count;
	char	north;
	char	south;
	char	east;
	char	west;
	int		collected;
}	t_player;

typedef struct s_map
{
	char	**map;
	char	**map_route;
	int		width;
	int		height;
	int		player;
	int		collectibles;
	int		exit;
	int		exit_x;
	int		exit_y;
	bool	exit_opened;
	int		enemies;
	void	*wall_img;
	void	*collectible_img;
	void	*exit_close_img;
	void	*exit_open_img;
	void	*enemy_img;
	void	*floor_img;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_player	player;
	t_map		map;
}	t_game;

# define TILE_SIZE 50
# define MOVE_SIZE 5
# define JUMP_SPEED 25  // Velocidade para subir
# define GRAVITY 25      // Velocidade para descer
# define JUMP_HEIGHT 150  // Distância máxima do salto
# define JUMP_DISTANCE 50  // Distância máxima do salto

void	read_map(char **argv, t_game *game);
void	exit_error(t_game *game);
int		ft_count_lines(int fd, t_game *game);
void	init_images(t_game *game);
void	render_map(t_game *game);
int		ft_line_length(int fd);
void	free_game_resources(t_game *game);
void	verify_map(t_game *game);
void	find_player_position(t_game *game);
void	error_wall(t_game *game);
void	error_none_player_exit_colec(t_game *game);
int		is_edge_wall(t_game *game, int x, int y);
void	is_map_retangle(t_game *game);
void	refresh_map(t_game *game);
void	calculate_movement(t_game *game);
void	movement_with_collision(t_game *game);
void	next_tile(t_game *game);
void	refresh_player(t_game *game);
int		is_wall(t_game *game, int x, int y);
void	exit_open(t_game *game);
void	init_walls_coners(t_game *game);
void	init_walls(t_game *game);
void	resize_images(t_game *game);
void	create_map(t_game *game, char *line, int i, int fd);
void	map_is_not_ber(char **argv, t_game *game);
void	player_key_move(t_game *game);
void	render_map_wall_floor(t_game *game, int x, int y);
void	render_map_others(t_game *game, int x, int y);
void	count_exit_colllectibles_player(t_game *game, int x, int y);
void	verify_lines_map(t_game *game);
void	flood_fill(t_game *game, int x, int y);
void	is_route_valid(t_game *game);
void	copy_map(t_game *game);
void	read_map_route(char **argv, t_game *game);
void	create_map_route(t_game *game, char *line, int i, int fd);
void	error_width_map(t_game *game);
void	error_more_player_exit(t_game *game);
void	free_images(t_game *game);
void	error_map_route(t_game *game);
void	error_route_is_not_valid(t_game *game);

#endif
