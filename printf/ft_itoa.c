/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:36:08 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/30 13:37:29 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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
	else
		ft_convert_nbr_to_char(result, i, wres);
	return (result);
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
