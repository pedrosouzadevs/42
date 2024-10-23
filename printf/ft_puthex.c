/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:12:23 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/10/23 16:41:19 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
void	ft_putchar(char c);
void	ft_putnbr_base_recursive(long nbr, char *base, int base_len);
int		ft_strlen(char *str);

int	is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
	{
		return (0);
	}
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base_recursive(long nbr, char *base, int base_len)
{
	if (nbr >= base_len)
		ft_putnbr_base_recursive(nbr / base_len, base, base_len);
	ft_putchar(base[nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *string)
{
	int		base_len;
	long	nb;
	char	*base;

	if (string == (char *)'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	base_len = ft_strlen(base);
	if (!is_valid(base))
		return ;
	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	ft_putnbr_base_recursive(nb, base, base_len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
