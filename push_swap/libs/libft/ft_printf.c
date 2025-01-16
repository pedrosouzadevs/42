/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:46:31 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/13 14:46:33 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			ft_transform(args, (char *)string, &count);
		}
		else
			ft_putchar_fd_c(*string, 1, &count);
		string++;
	}
	va_end(args);
	return (count);
}

void	ft_transform(va_list args, char *string, int *count)
{
	if (*string == 'c')
		ft_putchar_fd_c(va_arg(args, int), 1, count);
	else if (*string == 's')
		ft_trans_str(va_arg(args, char *), count);
	else if (*string == 'p')
		ft_trans_ptr(va_arg(args, void *), "0123456789abcdef", count);
	else if (*string == 'd')
		ft_trans_number(va_arg(args, int), count);
	else if (*string == 'i')
		ft_trans_number(va_arg(args, int), count);
	else if (*string == 'u')
		ft_trans_unsigned_number(va_arg(args, unsigned int), count);
	else if (*string == 'x')
		ft_trans_hex(va_arg(args, int), "0123456789abcdef", count);
	else if (*string == 'X')
		ft_trans_hex(va_arg(args, int), "0123456789ABCDEF", count);
	else if (*string == '%')
		ft_putchar_fd_c('%', 1, count);
}
