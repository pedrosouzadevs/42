/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:32:57 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/29 18:37:01 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_count_nbr(int n);
static char	*ft_convert_nbr_to_char(char *result, int i, int wres, char *base);

char	*ft_itoa_hex(int n, char *base)
{
	char	*result;
	int		i;
	int		wres;

	wres = n;
	i = ft_count_nbr(n);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		free(result);
		return (ft_strdup("-2147483648"));
	}
	else if (n == 0)
	{
		free(result);
		return (ft_strdup("0"));
	}
	else
		ft_convert_nbr_to_char(result, i, wres, base);
	return (result);
}

static int	ft_count_nbr(int n)
{
	int	count;
	int	wres;

	count = 0;
	wres = n;
	if (n == 0)
		count = 1;
	else
	{
		if (wres < 0)
		{
			wres = wres * -1;
			count++;
		}
		while (wres != 0)
		{
			wres = wres / 10;
			count++;
		}
	}
	return (count);
}

static char	*ft_convert_nbr_to_char(char *result, int i, int wres, char *base)
{
	int		j;

	j = i;
	while (wres > 0)
	{
		result[i - 1] = base[wres % 16];
		wres = wres / 16;
		i--;
	}
	result[j] = '\0';
	return (result);
}
