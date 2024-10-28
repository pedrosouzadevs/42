/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:12:09 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/28 18:48:14 by pedro-hm         ###   ########.fr       */
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
	char			*i;
	char			*d;
	char			*s;
	char			*p;
	char			*u;
	char			*x;
	char			*X;
}	t_node;

int				ft_printf(const char *string, ...);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
void			ft_trans_ptr(void *p, t_node *node, char *base);
void			ft_transform(t_node *node, va_list args, char *string);
void			ft_trans_number(int number, t_node *node, char *string);
void			ft_trans_hex(unsigned int number, t_node *node, char *base);
void			ft_trans_unsigned_number(unsigned int number, t_node *node);
char			*ft_join_strings(char * string, t_node *node);
char			*ft_itoa_hex(int n, char *base);
char			*ft_itoa(int n);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putchar(char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);


#endif // FT_PRINTF_H
