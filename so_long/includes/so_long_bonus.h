/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:28:19 by pdro              #+#    #+#             */
/*   Updated: 2025/02/10 16:03:22 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# include <time.h>
# include "../libs/libft/libft.h"

typedef struct s_animation
{
	void	*up_image[3];
	void	*down_image[3];
	void	*left_image[3];
	void	*right_image[3];
}	t_animation;

typedef struct s_player
{
	void		*image;
	t_animation	animation;
	t_animation	animation2;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
	int			dist_traveled;
	int			count;
	char		north;
	char		south;
	char		east;
	char		west;
	int			collected;
	int			animation_frame;
	int			last_animation_time;
}	t_player;

typedef struct s_enemy
{
	void		*image;
	mlx_image_t	*image_instance;
	t_animation	animation;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
	char		north;
	char		south;
	char		east;
	char		west;
	int			dist_up;
	int			dist_down;
	int			last_move_time;
}	t_enemy;

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
	void	*floor_img;
	void	*square_img;
	void	*box_img;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_player	player;
	t_map		map;
	t_enemy		enemy;
}	t_game;

# define TILE_SIZE 50
# define MOVE_SIZE 5
# define JUMP_SPEED 25  // Velocidade para subir
# define GRAVITY 25      // Velocidade para descer
# define JUMP_HEIGHT 150  // Distância máxima do salto
# define JUMP_DISTANCE 50  // Distância máxima do salto
# define ANIMATION_SPEED 200

void	read_map(char **argv, t_game *game);
void	exit_error(void);
int		ft_count_lines(int fd);
void	init_images(t_game *game);
void	render_map(t_game *game);
int		ft_line_length(int fd);
void	free_game_resources(t_game *game);
void	verify_map(t_game *game);
void	find_player_position(t_game *game);
void	error_wall(void);
void	error_none_player_exit_colec(void);
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
void	map_is_not_ber(char **argv);
void	animate_player(t_game *game);
int		error_readeble_map(void);
void	player_key_move(t_game *game);
void	render_map_wall_floor(t_game *game, int x, int y);
void	render_map_others(t_game *game, int x, int y);
void	count_exit_colllectibles_player(t_game *game, int x, int y);
void	animate_player_evolution(t_game *game);
void	verify_lines_map(t_game *game);
int		is_enemy(t_game *game, int x, int y);
void	find_enemy_position(t_game *game);
void	flood_fill(t_game *game, int x, int y);
void	is_route_valid(t_game *game);
void	copy_map(t_game *game);
void	read_map_route(char **argv, t_game *game);
void	create_map_route(t_game *game, char *line, int i, int fd);
void	update_text(t_game *game, char *new_text);
void	create_box(t_game *game);
void	update_box(t_game *game);
void	put_player_enemy_in_map(t_game *game);
void	update_box_text(t_game *game);
void	init_evol_d(t_game *game, int frame);
void	init_evol_s(t_game *game, int frame);
void	init_evol_a(t_game *game, int frame);
void	init_evol_w(t_game *game, int frame);
void	init_animation_w(t_game *game, int frame);
void	init_animation_s(t_game *game, int frame);
void	init_animation_d(t_game *game, int frame);
void	init_animation_a(t_game *game, int frame);

#endif
