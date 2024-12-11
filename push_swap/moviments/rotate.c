/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:58:38 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/12/11 18:15:42 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  Shift up all elements of stack a by 1.
// The first element becomes the last one.

#include "../push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = tmp;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}
void	rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	last = tmp;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
