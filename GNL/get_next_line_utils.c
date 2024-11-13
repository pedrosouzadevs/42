/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:54:20 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/13 17:15:42 by pedro-hm         ###   ########.fr       */
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
int	ft_strlen(const char *s)
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
	int		total_size;
	int		i;
	int		j;

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
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
char	*ft_copy(char *read_line, char *buffer, int bytes_read)
{
	char *temp;

	buffer[bytes_read] = '\0';
	temp = ft_strjoin(read_line, buffer);
	free(read_line);
	return (temp);
}
