/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:21:18 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/10 18:02:24 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libs/printf/ft_printf.h"

void	push(t_push *push_swap, t_mv type, t_bool print_mv)
{
	if (type == pa)
	{
		execute_push(&push_swap->stack_a, &push_swap->stack_b);
		if (print_mv)
				ft_printf("pa\n");
	}
	else if (type == pb)
	{
		execute_push(&push_swap->stack_b, &push_swap->stack_a);
		if (print_mv)
				ft_printf("pb\n");
	}
}
void	execute_push(t_stack **dst_stack, t_stack **src_stack)
{
	t_stack	*push_node;

	if (*src_stack == NULL)
		return ;
	push_node = *src_stack;
	*src_stack = (*src_stack)->next;
	if (*src_stack != NULL)
		(*src_stack)->prev = NULL;
	push_node->prev = NULL;
	if (*dst_stack == NULL)
	{
		*dst_stack = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst_stack;
		(*dst_stack)->prev = push_node;
		*dst_stack = push_node;
	}
}