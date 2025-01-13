/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:56:14 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/13 12:54:57 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty

void	pa(t_stack **stack_a, t_stack **stack_b, int *count)
{
	t_stack	*tmp;
	t_stack	*new;

	// if (!*stack_b)
	// 	return ;
	// tmp = *stack_b;
	// *stack_b = (*stack_b)->next;
	// tmp->next = *stack_a;
	// *stack_a = tmp;

	(*count)++;
}
void	pb(t_stack **stack_a, t_stack **stack_b, int *count)
{
	t_stack	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	ft_lstpop(stack_a);
	if (stack_b == NULL)
	{
		*stack_b = ft_lstnew(tmp->number);
		(*stack_b)->next = NULL;
	}
	else
	{
		ft_lstadd_front(stack_b, ft_lstnew(tmp->number));
	}
	(*count)++;
}
