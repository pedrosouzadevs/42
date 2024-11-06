/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:54:20 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/06 13:43:57 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*string;
	size_t		total_size;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	string = malloc(total_size * sizeof(char));
	if (!string)
		return (NULL);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		string[i + j] = s2[j];
		j++;
	}
	string[i + j] = '\0';
	return (string);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
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
