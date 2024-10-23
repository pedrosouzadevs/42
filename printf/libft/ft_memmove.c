/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:08:18 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/15 15:10:40 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destination;
	char		*source;
	size_t		i;

	i = 0;
	source = (char *)src;
	destination = (char *)dest;
	if (destination == NULL && source == NULL)
		return (NULL);
	if (source < destination && destination < source + n)
		while (n--)
			destination[n] = source[n];
	else
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dest);
}
