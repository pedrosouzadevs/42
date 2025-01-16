/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:13:50 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/14 14:25:18 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_sort(t_push *push_swap)
{
	t_stack	*smallest_node;
	int		smallest_pos;

	move_all_to_b(push_swap);
	if (!check_ordered(push_swap->stack_a))
		sort_three(push_swap);
	while (push_swap->stack_b != NULL)
	{
		set_position(push_swap->stack_a);
		set_position(push_swap->stack_b);
		set_match_node(push_swap->stack_a, push_swap->stack_b);
		set_cost(push_swap->stack_a, push_swap->stack_b);
		lcost_to_top(push_swap);
		push(push_swap, pa, TRUE);
	}
	set_position(push_swap->stack_a);
	smallest_pos = find_first_pos(push_swap->stack_a);
	smallest_node = get_node(push_swap->stack_a, smallest_pos);
	while (push_swap->stack_a != smallest_node)
		end_sorting(push_swap, smallest_node, a);
}

void	move_all_to_b(t_push *push_swap)
{
	t_stack	*second_bigger;
	t_stack	*biggest_node;
	t_stack	*smallest_node;
	int		biggest_pos;
	int		smallest_pos;

	second_bigger = get_second_bigger(push_swap->stack_a);
	biggest_pos = find_last_pos(push_swap->stack_a);
	biggest_node = get_node(push_swap->stack_a, biggest_pos);
	smallest_pos = find_last_pos(push_swap->stack_a);
	smallest_node = get_node(push_swap->stack_a, smallest_pos);
	while (push_swap->length_a > 3)
	{
		if (push_swap->stack_a == biggest_node || \
			push_swap->stack_a == second_bigger || \
			push_swap->stack_a == smallest_node)
			rotate(push_swap, ra, TRUE);
		push(push_swap, pb, TRUE);
		push_swap->length_a--;
	}
}

void	lcost_to_top(t_push *push_swap)
{
	t_stack	*smallest_node;
	int		smallest_pos;

	set_position(push_swap->stack_a);
	smallest_pos = find_first_pos(push_swap->stack_a);
	smallest_node = get_node(push_swap->stack_a, smallest_pos);
	if (smallest_node->above_center)
	{
		while (push_swap->stack_a->pos != smallest_pos)
			rotate(push_swap, ra, TRUE);
	}
	else if (!smallest_node->above_center)
	{
		while (push_swap->stack_a->pos != smallest_pos)
			reverse_rotate(push_swap, rra, TRUE);
	}
}

void	end_sorting(t_push *push_swap, t_stack *top_node, t_name name)
{
	if (name == a)
	{
		if (top_node->above_center)
			rotate(push_swap, ra, TRUE);
		else if (!(top_node->above_center))
			reverse_rotate(push_swap, rra, TRUE);
	}
	else if (name == b)
	{
		if (top_node->above_center)
			rotate(push_swap, rb, TRUE);
		else if (!(top_node->above_center))
			reverse_rotate(push_swap, rrb, TRUE);
	}
}
