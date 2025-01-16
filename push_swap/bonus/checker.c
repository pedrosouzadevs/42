/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:22:52 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/15 11:52:44 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char **argv)
{
	t_push	*push_swap;

	if (argc == 1)
		message_error(EXIT_NO_ARGS);
	else
	{
		push_swap = init_push_swap(argc, argv);
		validate_args(push_swap);
		init_stacks(push_swap);
		read_commands(push_swap);
		verify_stack(push_swap);
		free_and_close(push_swap, EXIT_SUCCESS);
	}
	return (0);
}
