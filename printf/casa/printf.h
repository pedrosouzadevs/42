#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct t_node
{
	char			*c;
}	t_node;

int				ft_printf(const char *string, ...);
void			ft_putchar_fd(char c, int fd, int *count);
void			ft_putstr_fd(char *s, int fd, int *count);

void	ft_trans_ptr(void *p, char *base, int *count);
void	ft_transform(va_list args, char *string, int *count);
void	ft_trans_number(va_list args, char *string, int *count);
void	ft_trans_hex(int number, char *base, int *count);
void			ft_trans_unsigned_number(va_list args, int *count);

char			*ft_itoa_hex(unsigned long n, char *base);
char			*ft_itoa(int n);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_count_nbr(int n);




#endif // FT_PRINTF_H
