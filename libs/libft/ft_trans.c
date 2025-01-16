/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:45:54 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/13 14:45:56 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_trans_str(char *str, int *count)
{
	if (!str)
	{
		ft_putchar_fd('(', 1, count);
		ft_putchar_fd('n', 1, count);
		ft_putchar_fd('u', 1, count);
		ft_putchar_fd('l', 1, count);
		ft_putchar_fd('l', 1, count);
		ft_putchar_fd(')', 1, count);
	}
	else
		ft_putstr_fd(str, 1, count);
}

void	ft_trans_ptr(void *p, char *base, int *count)
{
	unsigned long	n;

	if (!p)
	{
		ft_putchar_fd('(', 1, count);
		ft_putchar_fd('n', 1, count);
		ft_putchar_fd('i', 1, count);
		ft_putchar_fd('l', 1, count);
		ft_putchar_fd(')', 1, count);
	}
	else
	{
		n = (unsigned long)p;
		ft_putchar_fd('0', 1, count);
		ft_putchar_fd('x', 1, count);
		ft_itoa_ptr(n, base, count);
	}
}

void	ft_trans_hex(int number, char *base, int *count)
{
	int	n;

	n = number;
	ft_itoa_hex(n, base, count);
}

void	ft_trans_number(int number, int *count)
{
	int	n;

	n = number;
	ft_itoa(n, count);
}

void	ft_trans_unsigned_number(unsigned int number, int *count)
{
	unsigned int	n;

	n = number;
	ft_itoa_unsigned(n, count);
}
