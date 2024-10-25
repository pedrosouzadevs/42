/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:05 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/25 18:31:23 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int ft_printf(const char *string, ...)
{
	size_t	count;
	va_list args;
	va_start(args, string);

	count = 0;
	while (*string)
	{
		if (*string == '%')
		{
			ft_searching_porcentage((char *)string, args, &count);
			string++;
		}
 		else
			ft_putchar_fd(*string, 1);
		string++;
		count++;
	}
	va_end(args);
	return (count);
}

void	ft_putptr(void *p, size_t *count, char *base)
{
	unsigned long long	i;
	size_t				counting;
	char				numbers[12];
	int					j;

	j = 0;
	i = (unsigned long long)p;
	ft_putstr_fd("0x", 1);
	counting = *count;
	while (j < 12)
	{
		numbers[j] = (i % 16) + '0';
		i = i / 16;
		j++;
	}
	while (j > 0)
	{
		ft_putchar(base[(int)numbers[j]]);
		j--;
	}
	counting += 14;
}
void	ft_searching_porcentage(char *string, va_list args, size_t *count)
{
	char	*base;

	base = "0123456789abcdef";
	string++;
	if (*string == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		count++;
	}
	else if (*string == 's')
		ft_count_str(va_arg(args, char *), count);
	else if (*string == 'p')
		ft_putptr(va_arg(args, void *), count, base);
	else if (*string == 'd' || *string == 'i')
		ft_count_putnbr(va_arg(args, int), count);
	else if (*string == 'u')
		ft_putunbr(va_arg(args, int), count);
	else if (*string == 'x')
		ft_count_putnbr_base(va_arg(args, int), count, base);
	else if (*string == 'X')
		ft_count_putnbr_base(va_arg(args, int), count, "0123456789ABCDEF");
	else
		ft_putchar_fd(*string, 1);
}

void	ft_putunbr(int n, size_t *count)
{
	int	nbr;

	nbr = n;
	while (nbr > 9)
	{
		nbr = nbr/10;
		count++;
	}
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n > 9)
		ft_putunbr(n / 10, count);
	ft_putchar_fd((n % 10 + '0'), 1);
}


// int main(void)
// {
//     // Testando %c
//     ft_printf("Teste %c\n", 'A');
// 	printf("Teste %c\n", 'A');

//     // Testando %s
//     ft_printf("Teste %s\n", "Hello, World!");
// 	printf("Teste %s\n", "Hello, World!");

//     // Testando %p
//     int x = 22;
//     ft_printf("Teste %p\n", (void *)&x);
// 	printf("Teste %p\n", (void *)&x);

//     //Testando %d
//     ft_printf("Teste %d\n", 0);
// 	ft_printf("Teste %d\n", -1);
// 	ft_printf("Teste %d\n", 1);
// 	ft_printf("Teste %d\n", 9);
// 	ft_printf("Teste %d\n", 10);
// 	ft_printf("Teste %d\n", 11);
// 	ft_printf("Teste %d\n", 15);
// 	ft_printf("Teste %d\n", 16);
// 	ft_printf("Teste %d\n", 17);
// 	ft_printf("Teste %d\n", 99);
// 	ft_printf("Teste %d\n", 110);
// 	ft_printf("Teste %d\n", 101);

//     // Testando %i
//     ft_printf("Teste %i\n", 12345);
// 	printf("Teste %i\n", 12345);

//     // Testando %u
//     ft_printf("Teste %u\n", INT_MAX);
// 	printf("Teste %u\n", INT_MAX);

//     // Testando %x
//     ft_printf("Teste %x\n", 22);
// 	printf("Teste %x\n", 22);
//     // Testando %X
//     ft_printf("Teste %X\n", 22);
// 	printf("Teste %X\n", 22);

//     // Testando %%
//     ft_printf("Teste %%\n");
// 	printf("Teste %%\n");

// 	printf("Teste %d\n", ft_printf("Teste %c\n", 'A'));
// 	printf("Tste %d\n", printf("Teste %c\n", 'A'));
//     return 0;
// }
