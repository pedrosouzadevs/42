/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:48:48 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 21:37:38 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

void	render_character(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->character.character_ptr,
		x * WALL_SIZE, y * WALL_SIZE);
}

void	alternate_char_animation_left(t_game *game, int x, int y)
{
	static void	*frames[2] = {NULL, NULL};
	static int	current_frame = 0;

	if (!frames[0])
	{
		frames[0] = mlx_xpm_file_to_image(game->mlx_ptr,
				"resources/characters/character_to_left_32.xpm",
				&game->wall.width, &game->wall.height);
		frames[1] = mlx_xpm_file_to_image(game->mlx_ptr,
				"resources/characters/character_to_left_movement_32.xpm",
				&game->wall.width, &game->wall.height);
		if (!frames[0] || !frames[1])
		{
			write(1, "Error\n: failed to load character images\n", 40);
			exit(EXIT_FAILURE);
		}
	}
	current_frame = (current_frame + 1) % 2;
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, frames[current_frame],
		x * WALL_SIZE, y * WALL_SIZE);
	free_character_frames(frames, game->mlx_ptr);
}

void	alternate_char_animation_right(t_game *game, int x, int y)
{
	static void	*frames[2] = {NULL, NULL};
	static int	current_frame = 0;

	if (!frames[0])
	{
		frames[0] = mlx_xpm_file_to_image(game->mlx_ptr,
				"resources/characters/character_to_right_32.xpm",
				&game->wall.width, &game->wall.height);
		frames[1] = mlx_xpm_file_to_image(game->mlx_ptr,
				"resources/characters/character_to_right_movement_32.xpm",
				&game->wall.width, &game->wall.height);
		if (!frames[0] || !frames[1])
		{
			write(1, "Error\n: failed to load character images\n", 40);
			exit(EXIT_FAILURE);
		}
	}
	current_frame = (current_frame + 1) % 2;
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, frames[current_frame],
		x * WALL_SIZE, y * WALL_SIZE);
	free_character_frames(frames, game->mlx_ptr);
}

void	alternate_char_animation_up(t_game *game, int x, int y)
{
	static void	*frames[2] = {NULL, NULL};
	static int	current_frame = 0;

	if (!frames[0])
	{
		frames[0] = mlx_xpm_file_to_image(game->mlx_ptr,
				"resources/characters/character_to_up_32.xpm",
				&game->wall.width, &game->wall.height);
		frames[1] = mlx_xpm_file_to_image(game->mlx_ptr,
				"resources/characters/character_to_up_movement_32.xpm",
				&game->wall.width, &game->wall.height);
		if (!frames[0] || !frames[1])
		{
			write(1, "Error\n: failed to load character images\n", 40);
			exit(EXIT_FAILURE);
		}
	}
	current_frame = (current_frame + 1) % 2;
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, frames[current_frame],
		x * WALL_SIZE, y * WALL_SIZE);
	free_character_frames(frames, game->mlx_ptr);
}

void	alternate_char_animation_down(t_game *game, int x, int y)
{
	static void	*frames[2] = {NULL, NULL};
	static int	current_frame = 0;

	if (!frames[0])
	{
		frames[0] = mlx_xpm_file_to_image(game->mlx_ptr,
				"resources/characters/character_to_down_32.xpm",
				&game->wall.width, &game->wall.height);
		frames[1] = mlx_xpm_file_to_image(game->mlx_ptr,
				"resources/characters/character_to_down_movement_32.xpm",
				&game->wall.width, &game->wall.height);
		if (!frames[0] || !frames[1])
		{
			write(1, "Error\n: failed to load character images\n", 40);
			exit(EXIT_FAILURE);
		}
	}
	current_frame = (current_frame + 1) % 2;
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, frames[current_frame],
		x * WALL_SIZE, y * WALL_SIZE);
	free_character_frames(frames, game->mlx_ptr);
}
