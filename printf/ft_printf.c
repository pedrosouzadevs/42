/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:36:01 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/30 17:46:12 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int ft_printf(const char *string, ...)
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
			ft_putchar_fd(*string, 1, &count);
		string++;
	}
	va_end(args);
	return (count);
}

void	ft_transform(va_list args, char *string, int *count)
{
	if (*string == 'c')
		ft_putchar_fd(va_arg(args, int), 1, count);
	else if (*string == 's')
		ft_putstr_fd(va_arg(args, char *), 1, count);
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
		ft_putchar_fd('%', 1, count);
}

void	ft_trans_ptr(void *p, char *base, int *count)
{
	unsigned long	n;
	char			hex_str[14];
	int				i;

	if (p == NULL)
	{
		count += 5;
		ft_putstr_fd("(nil)", 1, count);
	}
	else
	{
		i = 13;
		n = (unsigned long)p;
		while (i >= 2)
		{
			hex_str[i] = base[n % 16];
			i--;
			n /= 16;
			if (n == 0)
				break ;
		}
		hex_str[0] = '0';
		hex_str[1] = 'x';
		i = 0;
		while (i < 14)
			write(1, &hex_str[i++], 1);
		*count += 14;
	}
}

void	ft_trans_hex(int number, char *base, int *count)
{
	char			*ptr;
	int				i;
	int				size_number;

	size_number = ft_count_nbr(number);
	i = 0;
	ptr = malloc(sizeof(char) * size_number + 1);
	if (ptr == NULL)
		return ;
	while (i < size_number)
	{
		ptr[i++] = base[number % 16];
		number = number / 16;
	}
	ptr[size_number] = '\0';
	i--;
    while (i >= 0)
		ft_putchar_fd(ptr[i--], 1, count);
	free(ptr);
}

void	ft_trans_number(int number, int *count)
{
	char			*ptr;
	int				i;
	int				size_number;

	i = 0;
	size_number = ft_count_nbr(number);
	number = ft_number_negative(number, count);
	if (number == 0)
		ft_putchar_fd('0', 1, count);
	else if (number > 0)
	{
		ptr = malloc(sizeof(char) * (size_number + 1));
		if (ptr == NULL)
			return ;
		while (number > 0)
		{
			ptr[i++] = (number % 10) + '0';
			number = number / 10;
		}
		i--;
		ptr[i + 1] = '\0';
		while (i >= 0)
			ft_putchar_fd(ptr[i--], 1, count);
		free(ptr);
	}
}

int	ft_number_negative(int number, int *count)
{
	if (number < 0)
	{
		ft_putchar_fd('-', 1, count);
		number = -number;
	}
	return (number);
}

void	ft_trans_unsigned_number(unsigned int number, int *count)
{
	char			*ptr;
	int				i;
	int				size_number;

	i = 0;
	size_number = ft_count_nbr(number);
	number = ft_number_negative(number, count);
	if (number == 0)
		ft_putchar_fd('0', 1, count);
	else if (number > 0)
	{
		ptr = malloc(sizeof(char) * (size_number + 1));
		if (ptr == NULL)
			return ;
		while (number > 0)
		{
			ptr[i++] = (number % 10) + '0';
			number = number / 10;
		}
		i--;
		ptr[i + 1] = '\0';
		while (i >= 0)
			ft_putchar_fd(ptr[i--], 1, count);
		free(ptr);
	}
}

// int main(void)
// {
//     // Testando %c
// 	int *x;

// 	x = 42;

// 	printf("Len: %d\n",ft_printf("Numero: %p", x));
// 	printf("Len: %d\n",printf("Numero: %p", x));
//     // printf("...............................................................\n");
//     // printf("Len: %d", ft_printf("Char: %c, String: %s, Ponteiro %p, Numero: %d, Numero: %i, Unumero: %u, Hexx: %x, HexX %X, Percentage: %%\n",
//     //           'A', "Hello, World!", (void *)&x, -10, 12345, INT_MAX, 42, 42, 'A'));
//     // printf("...............................................................\n");

//     // printf("Len %d" , printf("Char: %c, String: %s, Ponteiro %p, Numero: %d, Numero: %i, Unumero: %u, Hexx: %x, HexX %X, Percentage: %%\n",
//     //           'A', "Hello, World!", (void *)&x, -10, 12345, INT_MAX, 42, 42, 'A'));
//     // printf("...............................................................\n");
//     return 0;
// }

void printcmp(int a, int b)
{
    if (a == b)
    {
        ft_printf("OK\n");
    }
    else
        ft_printf("KO --!\n");
}
int main(void)
{
    char    *str = "12ozmouse";
    char    *nulo = NULL;
    char    **ptr;
    int     myfunc;
    int     original;
    ptr = &str;

    ft_printf("---------my func-----------\n");
    myfunc = ft_printf("c flag: %c|%c|%c|%c|%c\n", 'r', str[2], 97 - 32, *str, 48);

    ft_printf("\n---------original-----------\n");
	original = printf("c flag: %c|%c|%c|%c|%c\n", 'r', str[2], 97 - 32, *str, 48);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("s flag: %s|%s|%s|%s|%s|%s\n", "12ozmouse", str, str + 2, "", "-", nulo);

    ft_printf("\n---------original-----------\n");
    original = printf("s flag: %s|%s|%s|%s|%s|%s\n", "12ozmouse", str, str + 2, "", "-", nulo);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("p flag: %p|%p|%p|%p|%p|%p\n", str, &str, ptr, &ptr, nulo, &nulo);

    ft_printf("\n---------original-----------\n");
    original = printf("p flag: %p|%p|%p|%p|%p|%p\n", str, &str, ptr, &ptr, nulo, &nulo);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("d flag: %d|%d|%d|%d|%d\n", 7, -7, 0, 2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("d flag: %d|%d|%d|%d|%d\n", 7, -7, 0, 2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("i flag: %i|%i|%i|%i|%i\n", 7, -7, 0, 2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("i flag: %i|%i|%i|%i|%i\n", 7, -7, 0, 2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("u flag: %u|%u|%u|%u|%u\n", 7, -7, 0, 2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("u flag: %u|%u|%u|%u|%u\n", 7, -7, 0,
     2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("x flag: %x|%x|%x|%x|%x\n", 7, -7, 0, 2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("x flag: %x|%x|%x|%x|%x\n", 7, -7, 0, 2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("X flag: %X|%X|%X|%X|%X\n", 7, -7, 0, 2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("X flag: %X|%X|%X|%X|%X\n", 7, -7, 0, 2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("%% flag: %% | %%|%% \n");

    ft_printf("\n---------original-----------\n");
    original = printf("%% flag: %% | %%|%% \n");

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf(", I've printed %d characters!\n",
    ft_printf("d flag: %d|%d|%d|%d", 0, -37, 37, 187398217));

    ft_printf("\n---------original-----------\n");
    original = printf(", I've printed %d characters!\n",
     printf("d flag: %d|%d|%d|%d", 0, -37, 37, 187398217));

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf(", I've printed %d characters!\n",
     ft_printf("d flag: %d|%d|%d|%d", 0, -22222, 'n', 0));

    ft_printf("\n---------original-----------\n");
    original = printf(", I've printed %d characters!\n",
     printf("d flag: %d|%d|%d|%d", 0, -22222, 'n', 0));

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf(", I've printed %d characters!\n",
     ft_printf("INT MIN: %d", -2147483647 - 1));

    ft_printf("\n---------original-----------\n");
    original = printf(", I've printed %d characters!\n",
     printf("INT MIN: %d", -2147483647 - 1));

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("MIXED:%c|%s|%p|%d|%i|%u|%x|%X|%%\n", str[6], nulo, str, -912387, 00000, -99, 743, 743);

    ft_printf("\n---------original-----------\n");
    original = printf("MIXED:%c|%s|%p|%d|%i|%u|%x|%X|%%\n", str[6], nulo, str, -912387, 00000, -99, 743, 743);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);


    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf(NULL);

    ft_printf("\n---------original-----------\n");
    original = printf(NULL);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

}
