/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:54:46 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/07 16:00:16 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*string;
	int				i;

	i = 0;
	string = (unsigned char *)str;
	while (n > 0)
	{
		string[i] = 0;
		i++;
		n--;
	}
}
