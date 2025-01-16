/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:53:35 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/15 11:41:26 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_push	*init_push_swap(int argc, char **argv)
{
	t_push	*push_swap;

	push_swap = (t_push *)malloc(sizeof(t_push));
	if (!push_swap)
		message_error(EXIT_FAILURE);
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
	push_swap->length_a = 0;
	push_swap->length_b = 0;
	push_swap->check_argv = FALSE;
	if (argc == 2)
	{
		push_swap->argv = (ft_split(argv[1], ' '));
		push_swap->check_argv = TRUE;
	}
	else
		push_swap->argv = ++argv;
	return (push_swap);
}

void	init_stacks(t_push *push_swap)
{
	size_t	index;
	int		value;

	index = 0;
	value = 0;
	while (push_swap->argv[index])
	{
		value = ft_atoi(push_swap->argv[index]);
		link_node(&push_swap->stack_a, value);
		index++;
	}
	push_swap->length_a = stack_length(push_swap->stack_a);
	set_position(push_swap->stack_a);
}

void	link_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = create_node(value);
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
