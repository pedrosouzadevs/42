/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:46:50 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/13 14:46:52 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_itoa_ptr(unsigned long n, char *base, int *count)
{
	char				*result;
	int					i;
	unsigned long		wres;

	wres = n;
	i = ft_count_ptr_nbr(n);
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
		ft_convert_nbr_to_char_ptr(result, i, wres, base);
		ft_putstr_fd(result, 1, count);
		free(result);
	}
}

char	*ft_convert_nbr_to_char_ptr(char *result, int i,
			unsigned long wres, char *base)
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

int	ft_count_ptr_nbr(unsigned long n)
{
	int				count;
	unsigned long	wres;

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
