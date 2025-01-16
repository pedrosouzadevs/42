/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:13:25 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/15 11:35:03 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define EXIT_NO_ARGS -1
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

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

// Init Functions
t_push	*init_push_swap(int argc, char *argv[]);
void	init_stacks(t_push *push_swap);
void	link_node(t_stack **stack, int value);

// Validate Functions
void	validate_args(t_push *push_swap);
t_bool	check_duplication(char *args_list[]);
t_bool	check_letters(char *nbr);

// Node Functions
t_stack	*create_node(int value);
t_stack	*find_last_node(t_stack *stack);

// Stack Functions
t_bool	check_ordered(t_stack *stack);
size_t	stack_length(t_stack *stack);
void	free_stack(t_stack **stack);
int		ft_isatty(int fd);
void	set_position(t_stack *stack);

// Error Functions
void	message_error(short error_code);
void	free_and_close(t_push *push_swap, short exit_code);
void	clear_invalid_movment(t_push *push_swap, char *command);
void	free_split_list(char **split_list);

// Checker Functions
void	read_commands(t_push *push_swap);
void	execute_commands(t_push *push_swap, char *command);
void	verify_stack(t_push *push_swap);

// Command Functions
void	push(t_push *push_swap, t_mv type, t_bool print_checker);
void	execute_push(t_stack **dst_stack, t_stack **src_stack);
void	swap(t_push *push_swap, t_mv type, t_bool print_checker);
void	execute_swap(t_stack **stack);
void	rotate(t_push *push_swap, t_mv type, t_bool print_checker);
void	execute_rotate(t_stack **stack);
void	reverse_rotate(t_push *push_swap, t_mv type, t_bool print_checker);
void	execute_rev_rot(t_stack **stack);

#endif