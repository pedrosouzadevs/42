/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:58:48 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/13 11:17:29 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

#include "push_swap.h"

void	sa(t_stack **stack_a, int *count)
{
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	(*count)++;
}
void	sb(t_stack **stack_b, int *count)
{
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	(*count)++;
}

void	ss(t_stack **stack_a, t_stack **stack_b, int *count)
{
	sa(stack_a, count);
	sb(stack_b, count);
	(*count)--;
}
