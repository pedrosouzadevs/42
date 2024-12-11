/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:04:49 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/12/11 18:07:03 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Shift down all elements of stack a by 1.
// The last element becomes the first one.

#include "../push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = tmp;
	before_last = tmp;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = tmp;
}
void	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	last = tmp;
	before_last = tmp;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = tmp;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
