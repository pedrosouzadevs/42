/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:22:53 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/12/11 17:48:27 by pedro-hm         ###   ########.fr       */
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

#endif
