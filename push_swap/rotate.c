/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:58:38 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/13 11:17:43 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  Shift up all elements of stack a by 1.
// The first element becomes the last one.

#include "push_swap.h"

void	ra(t_stack **stack_a, int *count)
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
	(*count)++;
}
void	rb(t_stack **stack_b, int *count)
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
	(*count)++;
}

void	rr(t_stack **stack_a, t_stack **stack_b, int *count)
{
	ra(stack_a, count);
	rb(stack_b, count);
	(*count)--;
}
