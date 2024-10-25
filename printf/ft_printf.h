/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:12:09 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/23 14:12:11 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stddef.h>

int ft_printf(const char *string, ...);
void ft_putnbr_base(int nbr, char *string);
void ft_putptr(void *p);
void ft_putunbr(int n);
void ft_searching_porcentage(char *string, va_list args);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
size_t ft_strlen(const char *s);

#endif // FT_PRINTF_H
