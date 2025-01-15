/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:06:10 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/10 18:24:15 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_position(t_stack *stack)
{
	int	current_position;
	int	center_line;

	if (stack == NULL)
		return ;
	current_position = 0;
	center_line = stack_length(stack) / 2;
	while (stack != NULL)
	{
		stack->pos = current_position;
		if (current_position <= center_line)
			stack->above_center = TRUE;
		else if (current_position > center_line)
			stack->above_center = FALSE;
		stack = stack->next;
		++current_position;
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}

int	find_first_pos(t_stack *stack)
{
	int	pos;
	int	temp_min;

	pos = 0;
	temp_min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < temp_min)
		{
			temp_min = stack->value;
			pos = stack->pos;
		}
		stack = stack->next;
	}
	return (pos);
}

int	find_last_pos(t_stack *stack)
{
	int	pos;
	int	temp_max;

	pos = 0;
	temp_max = stack->value;
	while (stack != NULL)
	{
		if (stack->value > temp_max)
		{
			temp_max = stack->value;
			pos = stack->pos;
		}
		stack = stack->next;
	}
	return (pos);
}

int	get_match_node_cost(t_stack *stack, size_t len_match_stack)
{
	int	cost;

	cost = 0;
	if (stack->match_node->above_center)
		cost += stack->match_node->pos;
	else
		cost += (len_match_stack - stack->match_node->pos);
	return (cost);
}