
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
		{
			ft_putchar_fd(*string++, 1, &count);
		}
		string++;
	}
	va_end(args);
	return (count);
}

void	ft_transform(va_list args, char *string, int *count)
{
	if (*string == 'c')
		ft_putchar_fd(va_arg(args, int), 1, count);
	if (*string == 's')
		ft_putstr_fd(va_arg(args, char *), 1, count);
	if (*string == 'p')
		ft_trans_ptr(va_arg(args, void *), "0123456789abcdef", count);
	if (*string == 'd')
		ft_trans_number(args, string, count);
	if (*string == 'i')
		ft_trans_number(args, string, count);
	if (*string == 'u')
		ft_trans_unsigned_number(args, count);
	if (*string == 'x')
		ft_trans_hex(va_arg(args, int), "0123456789abcdef", count);
	if (*string == 'X')
		ft_trans_hex(va_arg(args, int), "0123456789ABCDEF", count);
	if (*string == '%')
		ft_putchar_fd('%', 1, count);
}

void	ft_trans_ptr(void *p, char *base, int *count)
{
	unsigned long	n;
	char			hex_str[12];
	int				i;

	i = 11;
	ft_putchar_fd('0', 1, count);
	ft_putchar_fd('x', 1, count);
	n = (unsigned long)p;
	while (i != 0)
	{
		hex_str[i--] = base[n % 16];
		n /= 16;
	}
	hex_str[12] = '\0';
    while (hex_str[i] != '\0')
	{
		ft_putchar_fd(hex_str[i], 1, count);
		i++;
	}
    // hex_str = ft_itoa_hex((int)n, base);
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
	while (i != 0)
	{
		ptr[i--] = base[number % 16];
		number = number / 16;
	}
	ptr[size_number] = '\0';
    while (ptr[i] != '\0')
		ft_putchar_fd(ptr[i++], 1, count);
	free(ptr);
}

void	ft_trans_number(va_list args, char *string, int *count)
{
	char			*ptr;
	int				n;

	n = va_arg(args, int);
	ptr = ft_itoa(n);
	if (*string == 'd')
		while (*ptr)
			ft_putchar_fd(*ptr++, 1, count);
	else
		while (*ptr)
			ft_putchar_fd(*ptr++, 1, count);
}

void	ft_trans_unsigned_number(va_list args, int *count)
{
	char			*ptr;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ptr = ft_itoa(n);
	while (*ptr)
		ft_putchar_fd(*ptr++, 1, count);
}

int main(void)
{
    // Testando %c
	int x = 22;
    printf("...............................................................\n");
    ft_printf("Meu Teste %c, Teste %s, Teste %p, Teste %d, Teste %i, Teste %u, Teste %x, Teste %X, Teste %%, Teste %d\n",
              'A', "Hello, World!", (void *)&x, 0, 12345, INT_MAX, 22, 22, 'A', 'A');
    printf("...............................................................\n");

    printf("Machine Teste %c, Teste %s, Teste %p, Teste %d, Teste %i, Teste %u, Teste %x, Teste %X, Teste %%, Teste %d\n",
           'A', "Hello, World!", (void *)&x, 0, 12345, INT_MAX, 22, 22, 'A', 'A');
    printf("...............................................................\n");

    return 0;
}
