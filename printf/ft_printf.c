/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:05 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/29 18:44:52 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>


int ft_printf(const char *string, ...)
{
	va_list	args;
	int	count;
	char	*str;
	char	*temp;
	char	*result;
	int		i;

	str = malloc(sizeof(char) * 1000);
	if (!str)
		return (-1);
	count = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			temp = ft_transform(args, (char *)string);
			ft_strjoin(str, temp);
			free(temp);
		}
		else
			*str++ = *string++;
		string++;
	}
	va_end(args);
	i = 0;
	while (str[i])
	{
		i++;
		count++;
	}
	result = malloc(sizeof(char) * (count + 1));
	if (!result)
		return (-1);
	result[count] = '\0';
	ft_putstr_fd(result, 1);
	return (count);
}

char	*ft_transform(va_list args, char *string)
{
	char	*temp;

	if (*string == 'c')
	{
		temp = malloc(2);
		if (!temp)
			return (NULL);
		temp[0] = (char)va_arg(args, int);
		temp[1] = '\0';
	}
	else if (*string == 's')
		temp = ft_strdup(va_arg(args, char *));
	else if (*string == 'p')
		temp = ft_trans_ptr(args, "0123456789abcdef");
	else if (*string == 'd' || *string == 'i')
		temp = ft_trans_number(args, string);
	else if (*string == 'u')
		temp = ft_trans_unsigned_number(args);
	else if (*string == 'x')
		temp = ft_trans_hex(args, "0123456789abcdef");
	else if (*string == 'X')
		temp = ft_trans_hex(args, "0123456789ABCDEF");
	else
		temp = ft_strdup("");
	return (temp);
}
char	*ft_trans_ptr(va_list args, char *base)
{
	char			*ptr;
	unsigned long	n;
	char			*tmp;

	n  = (unsigned long)va_arg(args, void *);
	ptr = malloc(sizeof(char) * 14);
	if (!ptr)
		return (NULL);
	ptr[0] = '0';
	ptr[1] = 'x';
	tmp = ft_itoa_hex(n, base);
	ft_strlcpy(ptr + 2, tmp, strlen(tmp));
	return (ptr);
}

char	*ft_trans_hex(va_list args, char *base)
{
	char			*ptr;
	unsigned int	n;

	n = va_arg(args, int);
	ptr = ft_itoa_hex(n, base);
	if (ft_strncmp(base, "0123456789abcdef", 16) == 0)
		return (ptr);
	else
		return (ptr);

}

char	*ft_trans_number(va_list args, char *string)
{
	char			*ptr;
	unsigned int	n;

	n = (va_arg(args, int));
	ptr = ft_itoa(n);
	if (*string == 'd')
		return (ptr);
	else
		return (ptr);
}

char	*ft_trans_unsigned_number(va_list args)
{
	char			*ptr;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ptr = ft_itoa(n);
	return (ptr);

}


// void	ft_join_strings(char * string, char *temp)
// {
// 	char	*ptr;

// 	ptr = temp;
// 	if (*string == 'c')
// 		ft_strlcpy(ptr, node->c, 1);
// 	if (*string == 's')
// 		ft_strlcpy(ptr, node->s, ft_strlen(node->s));
// 	if (*string == 'p')
// 		ft_strlcpy(ptr, node->p, ft_strlen(node->p));
// 	if (*string == 'd')
// 		ft_strlcpy(ptr, node->d, ft_strlen(node->d));
// 	if (*string == 'i')
// 		ft_strlcpy(ptr, node->i, ft_strlen(node->i));
// 	if (*string == 'u')
// 		ft_strlcpy(ptr, node->u, ft_strlen(node->u));
// 	if (*string == 'x')
// 		ft_strlcpy(ptr, node->x, ft_strlen(node->x));
// 	if (*string == 'X')
// 		ft_strlcpy(ptr, node->X, ft_strlen(node->X));
// }

// int	ft_count_words(t_node *node, va_list args, char *string)
// {
// 	int	count;

// 	count = 0;
// 	while (*string)
// 	{
// 		while (*string == '%')
// 		{
// 			string++;
// 			ft_transform(node, args, (char *)string);
// 			count += ft_strlen(ft_join_strings((char *)string, node));
// 			printf("count: %d\n", count);
// 		}
// 	}
// 	return (count);
// }

int main(void)
{
    // Testando %c
	printf("...............................................................\n");
	printf("Teste %c\n", 'A');
    ft_printf("Teste %c\n", 'A');

    // Testando %s
    ft_printf("Teste %s\n", "Hello, World!");
	printf("Teste %s\n", "Hello, World!");

    // Testando %p
    int x = 22;
    ft_printf("Teste %p\n", (void *)&x);
	printf("Teste %p\n", (void *)&x);

    //Testando %d
    ft_printf("Teste %d\n", 0);
	//

    // Testando %i
    ft_printf("Teste %i\n", 12345);
	printf("Teste %i\n", 12345);

    // Testando %u
    ft_printf("Teste %u\n", INT_MAX);
	printf("Teste %u\n", INT_MAX);

    // Testando %x
    ft_printf("Teste %x\n", 22);
	printf("Teste %x\n", 22);
    // Testando %X
    ft_printf("Teste %X\n", 22);
	printf("Teste %X\n", 22);

    // Testando %%
    ft_printf("Teste %%\n");
	printf("Teste %%\n");

	printf("Teste %d\n", ft_printf("Teste %c\n", 'A'));
	printf("Teste %d\n", printf("Teste %c\n", 'A'));
	printf("...............................................................");

    return 0;
}
