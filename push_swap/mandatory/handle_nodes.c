/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:38:59 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/13 19:01:41 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		message_error(EXIT_FAILURE);
	new_node->value = value;
	new_node->pos = 0;
	new_node->cost = 0;
	new_node->above_center = FALSE;
	new_node->lcost = FALSE;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->match_node = NULL;
	return (new_node);
}

t_stack	*find_last_node(t_stack *stack)
{
	if (stack == NULL)
		message_error(EXIT_FAILURE);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}
t_stack	*get_node(t_stack *stack, int pos)
{
	while (stack != NULL)
	{
		if (stack->pos == pos)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*get_lcost(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->lcost)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}