/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:46:57 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/13 14:46:59 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_hex(unsigned int n, char *base, int *count)
{
	char				*result;
	int					i;
	unsigned long		wres;

	wres = n;
	i = ft_count_hexnbr(n);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return ;
	if (n == 0)
	{
		free(result);
		ft_putstr_fd("0", 1, count);
	}
	else
	{
		ft_convert_nbr_to_char_hex(result, i, wres, base);
		ft_putstr_fd(result, 1, count);
		free(result);
	}
}

char	*ft_convert_nbr_to_char_hex(char *result, int i,
			unsigned int wres, char *base)
{
	int		j;

	j = i;
	if (wres == 0)
	{
		result[0] = base[0];
		result[1] = '\0';
		return (result);
	}
	while (wres > 0)
	{
		result[i - 1] = base[wres % 16];
		wres = wres / 16;
		i--;
	}
	result[j] = '\0';
	return (result);
}

int	ft_count_hexnbr(unsigned int n)
{
	int				count;
	unsigned int	wres;

	count = 0;
	wres = n;
	if (n == 0)
		count = 1;
	else
	{
		while (wres != 0)
		{
			wres = wres / 16;
			count++;
		}
	}
	return (count);
}
