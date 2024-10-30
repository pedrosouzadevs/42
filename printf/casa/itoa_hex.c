#include "includes/ft_printf.h"

static char	*ft_convert_nbr_to_char(char *result, int i, int wres, char *base);

char	*ft_itoa_hex(unsigned long n, char *base)
{
	char	*result;
	int		i;
	int		wres;

	wres = n;
	i = ft_count_nbr(n);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	else
		ft_convert_nbr_to_char(result, i, wres, base);
	return (result);
}

static char	*ft_convert_nbr_to_char(char *result, int i, int wres, char *base)
{
	int		j;

	j = i;
	while (wres > 0)
	{
		result[i - 1] = base[wres % 16];
		wres = wres / 16;
		i--;
	}
	result[j] = '\0';
	return (result);
}
