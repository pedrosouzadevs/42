/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:30:49 by pdro              #+#    #+#             */
/*   Updated: 2024/10/17 15:21:23 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list (*new));
void			ft_lstadd_back(t_list **alst, t_list (*new));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void*));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

// GNL FUNCTIONS
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif /*_BUFFER_SIZE_*/

char      *get_next_line(int fd);
char      *ft_check_buffer(int fd, char **rl);
char      *ft_get_temp(int bytes_read, char *buffer, char *rl);
char      *ft_extract_line(char *rl);

// PRINTF FUNCTIONS
int		ft_printf(const char *string, ...);
void	ft_putchar_fd_c(char c, int fd, int *count);
void	ft_putstr_fd_c(char *s, int fd, int *count);
void	ft_trans_ptr(void *p, char *base, int *count);
void	ft_transform(va_list args, char *string, int *count);
void	ft_trans_number(int number, int *count);
void	ft_trans_hex(int number, char *base, int *count);
void	ft_trans_unsigned_number(unsigned int number, int *count);
void	ft_trans_str(char *str, int *count);
void	ft_itoa_hex(unsigned int n, char *base, int *count);
void	ft_itoa_c(int n, int *count);
int		ft_count_nbr(int n);
void	ft_itoa_unsigned(unsigned int n, int *count);
int		ft_count_unbr(unsigned int n);
char	*ft_convert_nbr_to_char_hex(char *result, int i,
			unsigned int wres, char *base);
int		ft_count_hexnbr(unsigned int n);
int		ft_count_ptr_nbr(unsigned long n);
char	*ft_convert_nbr_to_char_ptr(char *result, int i,
			unsigned long wres, char *base);
void	ft_itoa_ptr(unsigned long n, char *base, int *count);
char	*ft_convert_nbr_to_char_unsigned(char *result,
			int i, unsigned int wres);

#endif
