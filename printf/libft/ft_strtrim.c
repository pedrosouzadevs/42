/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:55:12 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/16 14:51:42 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int	ft_ltrim(int i, const char *s1, const char *set);
int	ft_rtrim(const char *s1, const char *set, int size);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	int		i;
	int		size;
	int		start;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = ft_ltrim(0, s1, set);
	size = ft_rtrim(s1, set, ft_strlen((char *)s1) - 1);
	if (i > size)
	{
		string = malloc(1);
		string[0] = '\0';
		return (string);
	}
	start = 0;
	string = malloc(size - i + 2);
	if (string == NULL)
		return (NULL);
	while (i <= size)
		string[start++] = s1[i++];
	string[start] = '\0';
	return (string);
}

int	ft_ltrim(int i, const char *s1, const char *set)
{
	int	j;

	while (s1[i])
	{
		j = 0;
		while (set[j] && s1[i] != set[j])
			j++;
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

int	ft_rtrim(const char *s1, const char *set, int size)
{
	int	j;

	while (size >= 0)
	{
		j = 0;
		while (s1[size] != set[j] && set[j])
			j++;
		if (set[j] == '\0')
			break ;
		size--;
	}
	return (size);
}
