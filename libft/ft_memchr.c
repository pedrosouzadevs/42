/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:16:15 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/15 17:41:30 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*string;

	string = (char *)str;
	while (n--)
	{
		if (*string == (char)c)
			return ((char *)string);
		string++;
	}
	return ((void *)0);
}
