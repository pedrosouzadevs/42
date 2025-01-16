/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:45:45 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/13 14:45:47 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd_c(char c, int fd, int *count)
{
	write(fd, &c, 1);
	*count += 1;
}

void	ft_putstr_fd_c(char *s, int fd, int *count)
{
	while (*s)
		ft_putchar_fd(*s++, fd, count);
}

int	ft_count_nbr(int n)
{
	int	count;
	int	wres;

	count = 0;
	wres = n;
	if (n == 0)
		count = 1;
	else
	{
		if (wres < 0)
		{
			wres = wres * -1;
			count++;
		}
		while (wres != 0)
		{
			wres = wres / 10;
			count++;
		}
	}
	return (count);
}

int	ft_count_unbr(unsigned int n)
{
	int				count;
	unsigned int	wres;

	count = 0;
	wres = n;
	if (n == 0)
		count = 1;
	else
	{
		if (wres < 0)
			wres = wres * -1;
		while (wres != 0)
		{
			wres = wres / 10;
			count++;
		}
	}
	return (count);
}
