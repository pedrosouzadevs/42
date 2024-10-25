/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:12:09 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/25 18:22:07 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "../libs/libft/libft.h"
#include <unistd.h>
#include <stddef.h>

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


int		ft_printf(const char *string, ...);
void	ft_putnbr_base(int nbr, char *string);
void	ft_putptr(void *p, size_t *count, char *base);
void	ft_putunbr(int n, size_t *count);
void	ft_searching_porcentage(char *string, va_list args, size_t *count);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putnbr_base_recursive(long nbr, char *base, int base_len);
void	ft_putnbr_fd(int n, int fd);
void	ft_count_putnbr(int n, size_t *count);
void	ft_count_putnbr_base(int n, size_t *count, char *base);
void	ft_count_letters(char *string, va_list args, size_t *count);
void	ft_count_putunbr(int n, size_t *count);
void	ft_count_putptr(void *p, size_t *count);
void	ft_putnbr_fd(int n, int fd);
void	ft_count_str(char *string, size_t *count);
void	ft_final_count(char *string, va_list args, size_t *count);
void	ft_putnbr_base_fd(int n, int fd, char *base);

#endif // FT_PRINTF_H
