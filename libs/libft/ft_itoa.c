/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:03:18 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/15 16:52:20 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_nbr(int n);
char	*ft_convert_nbr_to_char(char *result, int i, int wres);

char	*ft_itoa(int n)
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
		ft_convert_nbr_to_char(result, i, wres);
	return (result);
}

int	ft_count_nbr(int n)
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
