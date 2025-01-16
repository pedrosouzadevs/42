/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:59:29 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/17 17:11:20 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_count_substring(char const *s, char c, size_t start)
{
	size_t	count;

	count = 0;
	while (s[start] && s[start++] != c)
		count++;
	return (count);
}

static char	**ft_allocate_split(char const *s, char c, size_t *i, size_t *j)
{
	char	**split;
	size_t	words;

	*i = 0;
	*j = 0;
	words = ft_wordcount(s, c);
	split = (char **)malloc((words + 1) * sizeof(char *));
	return (split);
}

static char	*ft_allocate_word(char const *s, char c, size_t i)
{
	char	*word;
	size_t	length;

	length = ft_count_substring(s, c, i);
	word = (char *)malloc((length + 1) * sizeof(char));
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	k;

	split = ft_allocate_split(s, c, &i, &j);
	if (!split || !s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			split[j] = ft_allocate_word(s, c, i);
			if (!split[j])
				return (NULL);
			k = 0;
			while (s[i] && s[i] != c)
				split[j][k++] = s[i++];
			split[j++][k] = '\0';
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}
