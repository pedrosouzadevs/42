/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:53:06 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/13 17:03:56 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	small_sort(t_push *push_swap)
{
	if (push_swap->length_a == 2)
		swap(push_swap, sa, TRUE);
	else if (push_swap->length_a == 3)
		sort_three(push_swap);
	else
		sort_few_elements(push_swap);
}

void	sort_three(t_push *push_swap)
{
	short	first_pos;
	short	last_pos;

	set_position(push_swap->stack_a);
	first_pos = find_first_pos(push_swap->stack_a);
	last_pos = find_last_pos(push_swap->stack_a);
	if (first_pos == 0)
	{
		reverse_rotate(push_swap, rra, TRUE);
		swap(push_swap, sa, TRUE);
	}
	else if (first_pos == 1)
	{
		if (last_pos == 0)
			rotate(push_swap, ra, TRUE);
		else
			swap(push_swap, sa, TRUE);
	}
	else if (first_pos == 2)
	{
		if (last_pos == 0)
			swap(push_swap, sa, TRUE);
		reverse_rotate(push_swap, rra, TRUE);
	}
}

void	sort_few_elements(t_push *push_swap)
{
	int	first_pos;

	while (stack_length(push_swap->stack_a) != 3)
	{
		first_pos = find_first_pos(push_swap->stack_a);
		if (push_swap->stack_a->pos != first_pos)
			lcost_to_top(push_swap);
		push(push_swap, pb, TRUE);
	}
	if (!check_ordered(push_swap->stack_a))
		sort_three(push_swap);
	while (push_swap->stack_b != NULL)
		push(push_swap, pa, TRUE);
}
