/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:27:23 by pdro              #+#    #+#             */
/*   Updated: 2024/10/28 18:34:53 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == s2[i])
		{
			if (s1[i] == '\0')
				return (0);
		}
		else
		{
			if ((unsigned char)s1[i] > (unsigned char)s2[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
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
