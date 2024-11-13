/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:46:17 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/13 14:46:21 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *string, ...);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_trans_ptr(void *p, char *base, int *count);
void	ft_transform(va_list args, char *string, int *count);
void	ft_trans_number(int number, int *count);
void	ft_trans_hex(int number, char *base, int *count);
void	ft_trans_unsigned_number(unsigned int number, int *count);
void	ft_trans_str(char *str, int *count);
void	ft_itoa_hex(unsigned int n, char *base, int *count);
void	ft_itoa(int n, int *count);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_count_nbr(int n);
void	ft_itoa_unsigned(unsigned int n, int *count);
int		ft_count_unbr(unsigned int n);
char	*ft_convert_nbr_to_char_hex(char *result, int i,
			unsigned int wres, char *base);
int		ft_count_hexnbr(unsigned int n);
int		ft_count_ptr_nbr(unsigned long n);
char	*ft_convert_nbr_to_char_ptr(char *result, int i,
			unsigned long wres, char *base);
void	ft_itoa_ptr(unsigned long n, char *base, int *count);
char	*ft_convert_nbr_to_char_unsigned(char *result,
			int i, unsigned int wres);

#endif // FT_PRINTF_H
