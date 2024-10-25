/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:45:18 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/25 18:12:08 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_count_str(char *string, size_t *count)
{
	// char	*str;

	// str = malloc(sizeof(char) * ft_strlen(string));
	// if (!str)
	// 	return ;
	// str = string;
	if (!string)
		return ;
	while (*string)
	{
		ft_putchar_fd(*string, 1);
		count++;
		string++;
	}
}
void	ft_count_putnbr(int n, size_t *count)
{
	int	nbr;

	nbr = n;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (nbr > 9)
	{
		nbr = nbr/10;
		count++;
	}
	if (n == 0)
		count++;
	ft_putnbr_fd(n, 1);
}
void	ft_count_putnbr_base(int n, size_t *count, char *base)
{
	int	nbr;

	nbr = n;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (nbr > 9)
	{
		nbr = nbr/10;
		count++;
	}
	if (n == 0)
		count++;
	ft_putnbr_base_fd(n, 1, base);
}
void	ft_final_count(char *string, va_list args, size_t *count)
{
	while (*string)
	{
		if (*string == '%')
		{
			ft_searching_porcentage((char *)string, args, count);
			string++;
		}
		else
		{
			ft_putchar_fd(*string, 1);
			count++;
		}
		string++;
	}
}
