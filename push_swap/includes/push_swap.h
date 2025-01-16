/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:24:10 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/15 11:16:33 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include "../libs/libft/libft.h"

# define INT_MAX		2147483647
# define INT_MIN		-2147483648
# define EXIT_NO_ARGS 	-1
# define EXIT_SUCCESS 	0
# define EXIT_FAILURE 	1

typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;

typedef struct s_stack
{
	int				value;
	int				pos;
	int				cost;
	t_bool			above_center;
	t_bool			lcost;
	struct s_stack	*match_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}t_stack;

typedef struct s_push
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_bool		check_argv;
	char		**argv;
	size_t		length_a;
	size_t		length_b;
}t_push;

typedef enum e_mv
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}t_mv;

typedef enum e_name
{
	a,
	b
}t_name;

//handle_errors functions
void	message_error(short error_code);
void	free_split_list(char **split_list);
void	free_and_close(t_push *push_swap, short exit_code);

//init_push_swap functions
t_push	*init_push_swap(int argc, char **argv);
void	init_stacks(t_push *push_swap);
void	link_node(t_stack **stack, int value);

//validate_arguments functions
void	validate_args(t_push *push_swap);
t_bool	check_letters(char *nbr);
t_bool	check_duplication(char *argv_split_list[]);

//handle_nodes functions
t_stack	*create_node(int value);
t_stack	*get_lcost(t_stack *stack);
t_stack	*find_last_node(t_stack *stack);
t_stack	*get_node(t_stack *stack, int pos);

//handle_stacks functions
void	free_stack(t_stack **stack);
size_t	stack_length(t_stack *stack);
t_bool	check_ordered(t_stack *stack);

//handle_sort functions
int		find_first_pos(t_stack *stack);
int		find_last_pos(t_stack *stack);
int		get_match_node_cost(t_stack *stack, size_t len_match_stack);
void	set_position(t_stack *stack);

//small_sort functions
void	small_sort(t_push *push_swap);
void	sort_three(t_push *push_swap);
void	sort_few_elements(t_push *push_swap);

//big_sort functions
void	big_sort(t_push *push_swap);
void	lcost_to_top(t_push *push_swap);
void	move_all_to_b(t_push *push_swap);
void	end_sorting(t_push *push_swap, t_stack *top_node, t_name name);
int		find_biggest_position(t_stack *stack);

//big_sort_utils functions
void	set_match_node(t_stack *stack_a, t_stack *stack_b);
void	set_cost(t_stack *stack_a, t_stack *stack_b);
void	set_lcost(t_stack *stack, int value);
t_stack	*get_second_bigger(t_stack *stack);
t_stack	*get_third_bigger(t_stack *stack);

//movments functions
void	swap(t_push *push_swap, t_mv type, t_bool print_mv);
void	execute_swap(t_stack **stack);
void	rotate(t_push *push_swap, t_mv type, t_bool print_mv);
void	execute_rotate(t_stack **t_stack);
void	push(t_push *push_swap, t_mv type, t_bool print_mv);
void	execute_push(t_stack **dst_stack, t_stack **src_stack);
void	reverse_rotate(t_push *push_swap, t_mv type, t_bool print_mv);
void	execute_rev_rot(t_stack **stack);

int		main(int argc, char **argv);

#endif