#include "includes/ft_printf.h"

void	ft_putchar_fd(char c, int fd , int *count)
{
	write(fd, &c, 1);
	*count += 1;
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	while (*s)
		ft_putchar_fd(*s++, fd, count);
}
