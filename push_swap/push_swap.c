/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:12:29 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/12/11 18:24:06 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc == 2)
	{
		stack_a = ft_create_stack_with_split(argv[1]);
		if (ft_lstsize(stack_a) == 1)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		stack_b = ft_create_stack_b();
	}
	else if (argc > 2)
	{
		stack_a = ft_create_stack_without_split(argv);
		stack_b = ft_create_stack_b();
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	while (stack_a)
	{
		printf("%d\n", stack_a->number);
		stack_a = stack_a->next;
	}
	free(stack_b);
	return (0);
}

t_stack *ft_create_stack_with_split(char *str)
{
	t_stack *stack_a;
	char **split;
	int i;

	i = 0;
	split = ft_split(str, ' ');
	stack_a = ft_lstnew(ft_atoi(split[i]));
	i++;
	while (split[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(split[i])));
		i++;
	}
	return (stack_a);
}
t_stack *ft_create_stack_without_split(char **argv)
{
	t_stack *stack_a;
	int i;

	i = 1;
	stack_a = ft_lstnew(ft_atoi(argv[i]));
	i++;
	while (argv[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (stack_a);
}

t_stack	*ft_create_stack_b(void)
{
	t_stack *stack_b;

	stack_b = malloc(sizeof(t_stack));
	return (stack_b);
}
