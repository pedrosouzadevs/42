/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:22:53 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/13 12:49:22 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


typedef struct s_stack
{
	int number;
	struct s_stack *next;
} t_stack;

t_stack *ft_create_stack_with_split(char *str);
t_stack *ft_create_stack_without_split(char **argv);
int	ft_lstsize(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int	ft_atoi(const char *str);
t_stack	*ft_lstnew(int content);
char	**ft_split(char const *s, char c);
t_stack	*ft_create_stack_b(void);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstpop(t_stack **stack);
void	ft_shuffle(t_stack **stack_a, t_stack **stack_b, int *count);
void	rr(t_stack **stack_a, t_stack **stack_b, int *count);
void	rb(t_stack **stack_b, int *count);
void	ra(t_stack **stack_a, int *count);
void	pb(t_stack **stack_a, t_stack **stack_b, int *count);
void	pa(t_stack **stack_a, t_stack **stack_b, int *count);
void	ss(t_stack **stack_a, t_stack **stack_b, int *count);
void	sb(t_stack **stack_b, int *count);
void	sa(t_stack **stack_a, int *count);
void	rrb(t_stack **stack_b, int *count);
void	rra(t_stack **stack_a, int *count);
void	rrr(t_stack **stack_a, t_stack **stack_b, int *count);
#endif
