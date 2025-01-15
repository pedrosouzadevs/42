/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:02:48 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/10 11:38:21 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	validate_args(t_push *push_swap)
{
	size_t	index;
	long	nbr;

	if (!check_duplication(push_swap->argv) || *push_swap->argv == NULL)
		free_and_close(push_swap, EXIT_FAILURE);
	
	index = 0;
	nbr = 0;
	while (push_swap->argv[index])
	{
		if(!check_letters(push_swap->argv[index]))
			free_and_close(push_swap, EXIT_FAILURE);
		nbr = ft_atoi(push_swap->argv[index]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_and_close(push_swap, EXIT_FAILURE); 
		index++;
	}
}
t_bool	check_duplication(char *argv_split_list[])
{
	 size_t	index;
	 size_t	index2;
	 long	nbr;

	 index = 0;
	 while (argv_split_list[index])
	 {
		nbr = ft_atoi(argv_split_list[index]);
		index2 = index + 1;
		while(argv_split_list[index2])
		{
			if (nbr == ft_atoi(argv_split_list[index2]))
				return (FALSE);
			index2++;
		}
		index++;
	 }
	 return (TRUE);
}
t_bool check_letters(char *nbr)
{
	size_t	index;
	t_bool	valid;

	index = 0;
	valid = TRUE;
	if (nbr[index] == '\0')
		valid = FALSE;
	while (nbr[index])
	{
		if ((nbr[index] == '-' || nbr[index] == '+') && !ft_isdigit(nbr[index +1 ]))
			valid = FALSE;
		else if (!ft_isdigit(nbr[index]))
		{
			if (nbr[index] != '-' && nbr[index] != '+')
				valid = FALSE;
		}
		index++;
	}
	return (valid);
}
