/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:52:28 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/10 18:00:46 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libs/printf/ft_printf.h"

void	swap(t_push *push_swap, t_mv type, t_bool print_mv)
{
	if (type == sa)
	{
		execute_swap(&push_swap->stack_a);
		if (print_mv)
			ft_printf("sa\n");
	}
	else if (type == sb)
	{
		execute_swap(&push_swap->stack_b);
		if (print_mv)
			ft_printf("sb\n");
	}
	else if (type == ss)
	{
		execute_swap(&push_swap->stack_a);
		execute_swap(&push_swap->stack_b);
		if (print_mv)
			ft_printf("ss\n");
	}
}

void	execute_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	if (second->next != NULL)
		second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*stack = second;
}