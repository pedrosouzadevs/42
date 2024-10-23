/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:05 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/23 16:49:20 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void	ft_putunbr(int n);
void	ft_putptr(void *p, char *string);
void	ft_putnbr_base(int nbr, char *string);
void	ft_searching_porcentage(char *string, va_list args);

typedef struct t_node
{
	char			c;
	int				i;
	int				d;
	char			*s;
	void			*p;
	unsigned int	u;
	int				x;
	int				X;
} t_node;


int ft_printf(const char *string, ...)
{
	va_list args;
	va_start(args, string);
	int	i;

	i = 0;
	while (*string)
	{
		if (*string == '%')
		{
			ft_searching_porcentage((char *)string, args);
			string++;
		}
 		else
			ft_putchar_fd(*string, 1);
		string++;
	}
	va_end(args);
	return (0);
}


void ft_putunbr(int n)
{
		int				fd;

	fd = 1;
	if (n < 0)
		n = -n;
	if (n > 9)
		ft_putunbr(n / 10);
	ft_putchar_fd(n % 10 + '0', fd);
}

void ft_putptr(void *p, char *string)
{
	unsigned long long	i;
	int	fd;

	fd = 1;
	i = (unsigned long long)p;
	ft_putstr_fd("0x", fd);
	ft_putnbr_base(i, string);
}

void	ft_searching_porcentage(char *string, va_list args)
{
	int	i;

	i = 1;
	string++;
	if (*string == 'c')
		ft_putchar_fd(va_arg(args, int), i);
	else if (*string == 's')
		ft_putstr_fd(va_arg(args, char *), i);
	else if (*string == 'p')
		ft_putptr(va_arg(args, void *), string);
	else if (*string == 'd' || *string == 'i')
		ft_putnbr_fd(va_arg(args, int), i);
	else if (*string == 'u')
		ft_putunbr(va_arg(args, int));
	else if (*string == 'x')
		ft_putnbr_base(va_arg(args, int), (char *)'x');
	else if (*string == 'X')
		ft_putnbr_base(va_arg(args, int), (char *)'X');
	else
		ft_putchar_fd(*string, i);
}

#include <stdio.h>
#include <limits.h>

int main(void)
{
    // Testando %c
    ft_printf("Teste %c\n", 'A');
	printf("Teste %c\n", 'A');

    // Testando %s
    ft_printf("Teste %s\n", "Hello, World!");
	printf("Teste %s\n", "Hello, World!");

    // Testando %p
    int x = 42;
    ft_printf("Teste %p\n", (void *)&x);
	printf("Teste %p\n", (void *)&x);

    // Testando %d
    ft_printf("Teste %d\n", -12345);
	printf("Teste %d\n", -12345);

    // Testando %i
    ft_printf("Teste %i\n", 12345);
	printf("Teste %i\n", 12345);

    // Testando %u
    ft_printf("Teste %u\n", INT_MAX);
	printf("Teste %u\n", INT_MAX);

    // Testando %x
    ft_printf("Teste %x\n", 255);
	printf("Teste %x\n", 255);
    // Testando %X
    ft_printf("Teste %X\n", 255);
	printf("Teste %X\n", 255);

    // Testando %%
    ft_printf("Teste %%\n");
	printf("Teste %%\n");

    return 0;
}
