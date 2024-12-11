/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:20:56 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 21:53:53 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	g_number_of_movements = 0;

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		close_game(game);
		exit(EXIT_FAILURE);
	}
	if (keysym == XK_a)
	{
		process_left_input(game);
	}
	if (keysym == XK_d)
	{
		process_right_input(game);
	}
	if (keysym == XK_w)
	{
		process_up_input(game);
	}
	if (keysym == XK_s)
	{
		process_down_input(game);
	}
	return (0);
}
