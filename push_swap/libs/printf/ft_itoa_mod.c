/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:46:37 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/14 14:32:55 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_nbr_to_char(char *result, int i, int wres);

void	ft_itoa_mod(int n, int *count)
{
	char	*result;
	int		i;
	int		wres;

	wres = n;
	i = ft_count_nbr(n);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return ;
	if (n == -2147483648)
	{
		free(result);
		ft_putstr_fd_mod("-2147483648", 1, count);
	}
	else if (n == 0)
	{
		free(result);
		ft_putstr_fd_mod("0", 1, count);
	}
	else
	{
		ft_convert_nbr_to_char(result, i, wres);
		ft_putstr_fd_mod(result, 1, count);
		free(result);
	}
}

char	*ft_convert_nbr_to_char(char *result, int i, int wres)
{
	int		j;

	j = i;
	if (wres < 0)
	{
		result[0] = '-';
		wres = wres * -1;
	}
	while (wres > 0)
	{
		result[i - 1] = (wres % 10) + '0';
		wres = wres / 10;
		i--;
	}
	result[j] = '\0';
	return (result);
}
