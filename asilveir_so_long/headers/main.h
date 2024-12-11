/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:51:19 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/09 16:56:08 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define WINDOW_WIDTH 1792
# define WINDOW_HEIGHT 896
# define MLX_ERROR 1
# define WALL_SIZE 32

extern int	g_number_of_movements;

typedef struct s_map
{
	char	**current_map;
}	t_map;	

typedef struct s_door
{
	void	*door_ptr;
	char	*addr;
	char	*location;
}	t_door;

typedef struct s_collectible
{
	void	*collectible_ptr;
	char	*addr;
}	t_collectible;

typedef struct s_background
{
	void	*background_ptr;
	char	*addr;
}	t_background;	

typedef struct s_character
{
	void	*character_ptr;
	char	*addr;
}	t_character;

typedef struct s_wall
{
	void	*wall_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_wall;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_background	background;
	t_img			img;
	t_wall			wall;
	t_character		character;
	t_map			map;
	t_collectible	collectible;
	t_door			door;
}	t_game;

//background_utils_1.c
int		background_entire_screen_put(t_game *game, char **map);
int		background_specific_position_put(t_game *game, int x, int y);

//background_utils_2.c
int		put_background_right(t_game *game, int i, int j, char **map);
int		put_background_left(t_game *game, int i, int j, char **map);
int		put_background_up(t_game *game, int i, int j, char **map);
int		put_background_down(t_game *game, int i, int j);

//flood_fill_utils_1.c
int		count_columns(char **map);
void	dfs(char **map, int current_row, int current_column, char new_char);
void	flood_fill(char **map, int current_row,
			int current_column, char new_char);

//flood_fill_utils_2.c
int		check_if_win_is_possible(char **map_copy);
int		search_flood_fill(t_game *game);
char	**copy_map(char **original);
void	free_map(char **map);

//handle_events.c
int		handle_no_event(void	*game);
int		check_collectibles(t_game *game);

//map_init.c
char	**read_map(char *argv);
char	*join_strings(char const *s1, char const *s2);
char	**parse_map(char **map, int argc, char **argv);
void	execute_map_validations(char **map);
int		check_if_map_file_is_ber(char *argv);

//map_utils.c
int		rows_of_map_exist(t_game *game, int row);
int		current_row_exists(t_game *game, int row, int column);
int		found_character_position(t_game *game, int row, int column);
int		found_door_position(t_game *game, int row_number, int column_number);

//map_validation_utils_1.c
int		count_rows(char **map);
int		check_if_map_is_rectangular(char **map);
int		search_walls_horizontally(char **map);
int		search_walls_vertically(char **map);
int		map_is_surrounded_by_walls(char **map);

//map_validation_utils_2.c
int		search_exit(char **map);
int		search_collectible(char **map);
int		search_player(char **map);
int		search_forbidden_character(char **map);
int		only_one_player(char **map);

//map_validation_utils_3.c
int		only_one_exit(char **map);

//move_down.c
int		move_player_down(t_game *game, int row, int column);
int		try_move_down(t_game *game, int row, int column);
void	print_number_of_movements(void);

//move_left.c
int		move_player_left(t_game *game, int row, int column);
int		try_move_left(t_game *game, int row, int column);

//move_right.c
int		move_player_right(t_game *game, int row, int column);
int		try_move_right(t_game *game, int row, int column);

//move_up.c
int		move_player_up(t_game *game, int row, int column);
int		try_move_up(t_game *game, int row, int column);

//process_inputs.c
int		handle_keypress(int keysym, t_game *game);

//process_movements.c
int		door_is_locked(t_game *game);
int		process_left_input(t_game *game);
int		process_right_input(t_game *game);
int		process_up_input(t_game *game);
int		process_down_input(t_game *game);

//render_character.c
void	render_character(t_game *game, int x, int y);
void	alternate_char_animation_left(t_game *game, int x, int y);
void	alternate_char_animation_right(t_game *game, int x, int y);
void	alternate_char_animation_up(t_game *game, int x, int y);
void	alternate_char_animation_down(t_game *game, int x, int y);

//render_collectible.c
void	render_collectible(t_game *game, int x, int y);

//render_door.c
int		replace_door(t_game *game, int i, int j);
int		render_unlocked_door(t_game *game);
void	render_door(t_game *game, int x, int y);

//render_map.c
int		render(t_game *game, char **map);
int		render_map(t_game *game, char **map);
void	render_wall_tile(t_game *game, int x, int y);

//setup_game.c
int		setup_screen(t_game *game);
int		setup_game(t_game *game);

//close_game.c
int		close_game(t_game *game);
int		close_game_when_x_is_clicked(void *param);
void	free_character_frames(void *frames[2], void *mlx_ptr);
#endif