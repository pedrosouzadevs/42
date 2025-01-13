/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:20:48 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/13 12:50:47 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = content;
	new->next = NULL;
	return (new);
}
int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*list;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	list = *lst;
	while (list->next)
		list = list->next;
	list -> next = new;
}
int	ft_lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
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

void	ft_lstpop(t_stack **stack)
{
		t_stack	*next_node;

		next_node = NULL;
		if (*stack == NULL)
			return ;
		next_node = (*stack)->next;
		stack = &next_node;
}
