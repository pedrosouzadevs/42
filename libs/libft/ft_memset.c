/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:24:50 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/07 15:54:25 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int				i;
	unsigned char	*string;

	string = (unsigned char *)str;
	i = 0;
	while (n > 0)
	{
		string[i] = c;
		i++;
		n--;
	}
	return (str);
}
