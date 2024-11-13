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

void	ft_putchar_fd(char c, int fd, int *count)
{
	write(fd, &c, 1);
	*count += 1;
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	while (*s)
		ft_putchar_fd(*s++, fd, count);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == s2[i])
		{
			if (s1[i] == '\0')
				return (0);
		}
		else
		{
			if ((unsigned char)s1[i] > (unsigned char)s2[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
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
