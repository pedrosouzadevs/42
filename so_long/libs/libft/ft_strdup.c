/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:39:44 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/15 14:11:56 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dest;
	int		i;

	len = ft_strlen(src);
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
