/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:12:29 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/13 13:24:50 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int	*count;

	if (argc == 2)
	{
		stack_a = ft_create_stack_with_split(argv[1]);
		if (ft_lstsize(stack_a) == 1)
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	else if (argc > 2)
		stack_a = ft_create_stack_without_split(argv);

	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	stack_b = ft_create_stack_b();
	ft_shuffle(&stack_a, &stack_b, count);
	while (stack_a)
	{
		printf("%d\n", stack_a->number);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("Stack B\n");
		if (ft_lstsize(stack_b) == 0)
			break ;
		else
		{
			printf("%d\n", stack_b->number);
			stack_b = stack_b->next;
		}
	}
	free(stack_b);
	return (0);
}

void ft_shuffle(t_stack **stack_a, t_stack **stack_b, int *count)
{
	t_stack *tmp;

	count = 0;
	while (*stack_a)
		sa(stack_a, count);

}
