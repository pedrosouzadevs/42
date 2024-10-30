/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:12:09 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/30 14:41:46 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct t_node
{
	char			*c;
}	t_node;

int				ft_printf(const char *string, ...);
void			ft_putchar_fd(char c, int fd, int *count);
void			ft_putstr_fd(char *s, int fd, int *count);

void	ft_trans_ptr(void *p, char *base, int *count);
void	ft_transform(va_list args, char *string, int *count);
void	ft_trans_number(int number, int *count);
void	ft_trans_hex(int number, char *base, int *count);
void			ft_trans_unsigned_number(unsigned int number, int *count);

char			*ft_itoa_hex(unsigned long n, char *base);
char			*ft_itoa(int n);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_count_nbr(int n);

int	ft_number_negative(int number, int *count);



#endif // FT_PRINTF_H
