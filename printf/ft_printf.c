/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:05 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/28 18:51:16 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int ft_printf(const char *string, ...)
{
	va_list	args;
	size_t	count;
	char	*str;
	t_node	*node;

	str = malloc(sizeof(char) * 100);
	node = malloc(sizeof(t_node));
	if (!str || !node)
		return (-1);
	count = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			ft_transform(node, args, (char *)string);
			ft_strjoin(str, ft_join_strings((char *)string, node));
		}
		else
		{
			str = (char *)string;
			str++;
			string++;
		}
		string++;
	}
	va_end(args);
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	return (count);
}

void	ft_transform(t_node *node, va_list args, char *string)
{
	char	character;

	if (*string == 'c')
	{
		character = (char)va_arg(args, int);
		node->c = &character;
	}
	if (*string == 's')
		node->s = va_arg(args, char *);
	if (*string == 'p')
		ft_trans_ptr(va_arg(args, void *), node, "0123456789abcdef");
	if (*string == 'd')
		ft_trans_number(va_arg(args, int), node, string);
	if (*string == 'i')
		ft_trans_number(va_arg(args, int), node, string);
	if (*string == 'u')
		ft_trans_unsigned_number(va_arg(args, unsigned int), node);
	if (*string == 'x')
		ft_trans_hex(va_arg(args, int), node, "0123456789abcdef");
	if (*string == 'X')
		ft_trans_hex(va_arg(args, int), node, "0123456789ABCDEF");
}

void	ft_trans_ptr(void *p, t_node *node, char *base)
{
	char			*ptr;
	unsigned long	n;

	ptr = malloc(sizeof(char) * 14);
	if (!ptr)
		return ;
	ptr[0] = '0';
	ptr[1] = 'x';
	n = (unsigned long)p;
	ptr = ft_itoa_hex(n, base);
	node->p = ptr;
}

void	ft_trans_hex(unsigned int number, t_node *node, char *base)
{
	char			*ptr;
	unsigned int	n;

	n = number;
	ptr = ft_itoa_hex(n, base);
	if (ft_strncmp(base, "0123456789abcdef", 16) == 0)
		node->x = ptr;
	else
		node->X = ptr;
}

void	ft_trans_number(int number, t_node *node, char *string)
{
	char			*ptr;
	unsigned int	n;

	n = number;
	ptr = ft_itoa(n);
	if (*string == 'd')
		node->d = ptr;
	else
		node->i = ptr;
}

void	ft_trans_unsigned_number(unsigned int number, t_node *node)
{
	char			*ptr;
	unsigned int	n;

	n = number;
	ptr = ft_itoa(n);
	node->u = ptr;
}

char	*ft_join_strings(char * string, t_node *node)
{
	char	*ptr;

	ptr = NULL;

	if (*string == 'c')
		ft_strlcpy(ptr, node->c, 1);
	if (*string == 's')
		ft_strlcpy(ptr, node->s, ft_strlen(node->s));
	if (*string == 'p')
	{
		ft_strlcpy(ptr, node->p, ft_strlen(node->p));
		printf("%s", ptr);
	}
	if (*string == 'd')
	{
		ft_strlcpy(ptr, node->d, ft_strlen(node->d));
		printf("%s", ptr);
	}
	if (*string == 'i')
	{
		ft_strlcpy(ptr, node->i, ft_strlen(node->i));
		printf("%s", ptr);
	}
	if (*string == 'u')
	{
		ft_strlcpy(ptr, node->u, ft_strlen(node->u));
		printf("%s", ptr);
	}
	if (*string == 'x')
	{
		ft_strlcpy(ptr, node->x, ft_strlen(node->x));
		printf("%s", ptr);
	}
	if (*string == 'X')
	{
		ft_strlcpy(ptr, node->X, ft_strlen(node->X));
		printf("%s", ptr);
	}
	return (ptr);
}

// int main(void)
// {
//     // Testando %c
// 	printf("...............................................................\n");
//     ft_printf("Meu Teste %c\n", 'A');
// 	printf("Machine Teste %c\n", 'A');

//     // Testando %s
//     ft_printf("Teste %s\n", "Hello, World!");
// 	printf("Teste %s\n", "Hello, World!");

//     // Testando %p
//     int x = 22;
//     ft_printf("Teste %p\n", (void *)&x);
// 	printf("Teste %p\n", (void *)&x);

//     //Testando %d
//     ft_printf("Teste %d\n", 0);
// 	//

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
// 	printf("Teste %d\n", printf("Teste %c\n", 'A'));
// 	printf("...............................................................");

//     return 0;
// }
