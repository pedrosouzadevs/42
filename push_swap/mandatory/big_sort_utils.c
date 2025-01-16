/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:53:19 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/14 14:36:29 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_match_node(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*match_node;
	int		current_best;

	while (stack_b != NULL)
	{
		current_best = INT_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value && \
				current_a->value < current_best)
			{
				current_best = current_a->value;
				match_node = current_a;
			}
			current_a = current_a->next;
		}
		if (current_best != INT_MAX)
			stack_b->match_node = match_node;
		else
			stack_b->match_node = get_node(stack_a, \
			find_first_pos(stack_a));
		stack_b = stack_b->next;
	}
}

void	set_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head;
	size_t	length_a;
	size_t	length_b;
	int		cost;

	head = stack_b;
	length_a = stack_length(stack_a);
	length_b = stack_length(stack_b);
	cost = 0;
	while (stack_b != NULL)
	{
		if (stack_b->above_center)
			cost = stack_b->pos;
		else
			cost = length_b - stack_b->pos;
		cost += get_match_node_cost(stack_b, length_a);
		if (stack_b == get_node(head, find_last_pos(head)) || \
			stack_b == get_second_bigger(head) || \
			stack_b == get_third_bigger(head))
			cost -= 1;
		else if (stack_b == get_node(head, find_first_pos(head)))
			cost += 1;
		stack_b->cost = cost;
		stack_b = stack_b->next;
	}
}

void	set_lcost(t_stack *stack, int value)
{
	while (stack != NULL)
	{
		stack->lcost = value;
		stack = stack->next;
	}
}

t_stack	*get_second_bigger(t_stack *stack)
{
	t_stack	*biggest;
	t_stack	*second_bigger;

	biggest = get_node(stack, find_last_pos(stack));
	second_bigger = NULL;
	while (stack != NULL)
	{
		if ((stack != biggest) && (second_bigger == NULL
				|| stack->value > second_bigger->value))
			second_bigger = stack;
		stack = stack->next;
	}
	return (second_bigger);
}

t_stack	*get_third_bigger(t_stack *stack)
{
	t_stack	*biggest;
	t_stack	*second_bigger;
	t_stack	*third_bigger;

	biggest = get_node(stack, find_last_pos(stack));
	second_bigger = get_second_bigger(stack);
	third_bigger = NULL;
	while (stack != NULL)
	{
		if ((stack != biggest) && (stack != second_bigger) && \
			(third_bigger == NULL || stack->value > third_bigger->value))
			third_bigger = stack;
		stack = stack->next;
	}
	return (third_bigger);
}
