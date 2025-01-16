/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:14:23 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/15 11:41:18 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	message_error(short error_code)
{
	if (error_code == EXIT_FAILURE)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(error_code);
}

void	free_and_close(t_push *push_swap, short exit_code)
{	
	if (push_swap->argv && push_swap->check_argv == TRUE)
		free_split_list(push_swap->argv);
	if (push_swap->stack_a)
		free_stack(&push_swap->stack_a);
	if (push_swap->stack_b)
		free_stack(&push_swap->stack_b);
	free(push_swap);
	message_error(exit_code);
}

void	free_split_list(char **split_list)
{
	size_t	index;

	index = 0;
	while (split_list[index] != NULL)
	{
		free(split_list[index]);
		index++;
	}
	free(split_list);
}
