/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:46:44 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/14 14:32:23 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_unsigned(unsigned int n, int *count)
{
	char				*result;
	int					i;
	unsigned int		wres;

	wres = n;
	i = ft_count_unbr(n);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return ;
	if (n == 0)
	{
		free(result);
		ft_putstr_fd_mod("0", 1, count);
	}
	else
	{
		ft_convert_nbr_to_char_unsigned(result, i, wres);
		ft_putstr_fd_mod(result, 1, count);
		free(result);
	}
}

char	*ft_convert_nbr_to_char_unsigned(char *result, int i, unsigned int wres)
{
	int		j;

	j = i;
	while (wres > 0)
	{
		result[i - 1] = (wres % 10) + '0';
		wres = wres / 10;
		i--;
	}
	result[j] = '\0';
	return (result);
}
