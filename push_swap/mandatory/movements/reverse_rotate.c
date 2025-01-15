/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:33:05 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/10 18:00:42 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libs/printf/ft_printf.h"

void	reverse_rotate(t_push *push_swap, t_mv type, t_bool print_mv)
{
	if (type == rra)
	{
		execute_rev_rot(&push_swap->stack_a);
		if (print_mv)
			ft_printf("rra\n");
	}
	else if (type == rrb)
	{
		execute_rev_rot(&push_swap->stack_b);
		if (print_mv)
			ft_printf("rrb\n");
	}
	else if (type == rrr)
	{
		execute_rev_rot(&push_swap->stack_a);
		execute_rev_rot(&push_swap->stack_b);
		if (print_mv)
			ft_printf("rrr\n");
	}
}
void	execute_rev_rot(t_stack **stack)
{
	t_stack	*current_first;
	t_stack	*new_first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current_first = *stack;
	new_first = find_last_node(*stack);
	new_first->prev->next = NULL;
	current_first->prev = new_first;
	new_first->prev = NULL;
	new_first->next = current_first;
	*stack = new_first;	
}