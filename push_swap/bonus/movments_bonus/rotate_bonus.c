/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:28:58 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/15 11:14:53 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	rotate(t_push *push_swap, t_mv type, t_bool print_mv)
{
	if (type == ra)
	{
		execute_rotate(&push_swap->stack_a);
		if (print_mv)
			ft_printf("ra\n");
	}
	else if (type == rb)
	{
		execute_rotate(&push_swap->stack_b);
		if (print_mv)
			ft_printf("rb\n");
	}
	else if (type == rr)
	{
		execute_rotate(&push_swap->stack_a);
		execute_rotate(&push_swap->stack_b);
		if (print_mv)
			ft_printf("rr\n");
	}
}

void	execute_rotate(t_stack **stack)
{
	t_stack	*current_last;
	t_stack	*new_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current_last = find_last_node(*stack);
	new_last = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current_last->next = new_last;
	new_last->prev = current_last;
	new_last->next = NULL;
}
