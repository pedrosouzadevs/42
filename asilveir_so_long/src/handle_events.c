/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:50:32 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 20:07:35 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	handle_no_event(void	*game)
{
	if (!game)
		return (0);
	return (0);
}

int	check_collectibles(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map.current_map[j])
	{
		i = 0;
		while (game->map.current_map[j][i])
		{
			if (game->map.current_map[j][i] == 'C')
			{
				return (1);
			}
			i++;
		}
		j++;
	}
	render_unlocked_door(game);
	return (0);
}
