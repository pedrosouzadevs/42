/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:05:05 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/14 14:30:17 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	if (!s)
	size = ft_strlen(s);
		return (NULL);
	if (size < start)
		return (ft_strdup(""));
	if (size < start + len)
		len = size - start;
	substring = (char *)malloc(len + 1);
	if (!substring)
		return (NULL);
	while (i < len && s[start + i])
	{
		substring[i] = s[i + start];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
