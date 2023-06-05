/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:51:32 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/23 15:38:48 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int					ft_atoi(const char *str);

void				ft_bzero(void *s, size_t n);

void				*ft_calloc(size_t nmemb, size_t size);

int					ft_isalnum(int a);

int					ft_isalpha(int a);

int					ft_isascii(int c);

int					ft_isdigit(int a);

int					ft_isprint(int a);

char				*ft_itoa(int n);

void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstadd_front(t_list **lst, t_list *new);

void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstdelone(t_list *lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

t_list				*ft_lstlast(t_list *lst);

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

t_list				*ft_lstnew(void *content);

int					ft_lstsize(t_list *lst);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memset(void *s, int c, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				ft_putchar_fd(char c, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

void				ft_putstr_fd(char const *s, int fd);

char				**ft_split(char const *s, char c);

char				*ft_strchr(const char *s, int c);

char				*ft_strdup(const char *s);

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strjoin(char const *s1, char const *s2);

size_t				ft_strlcat(char *dest, char *src, size_t size);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);

size_t				ft_strlen(const char *s);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strnstr(const char *haystack, const char *needle,
						size_t n);

char				*ft_strrchr(const char *s, int c);

char				*ft_strtrim(char const *s1, char const *set);

char				*ft_substr(char const *s, unsigned int start, size_t len);

int					ft_tolower(int c);

int					ft_toupper(int c);

/*printf functions*/
int					ft_printf(const char *str, ...);
int					ft_output(va_list ptr, char c);
int					ft_printchar(int a);
int					ft_printstr(char *str);
int					ft_printnbr(int n);
int					ft_printhex(unsigned int n, char c);
int					ft_hexlen(unsigned int n);
void				ft_puthex(unsigned int n, char c);
int					ft_printunsigned(unsigned int n);
int					ft_numlen(unsigned int n);
char				*ft_uitoa(unsigned int n);
int					ft_printptr(unsigned long long n);
int					ft_ptrlen(unsigned long long n);
void				ft_putptr(unsigned long long n);

/*get next line functions*/

char				*get_next_line(int fd);
char				*ft_strjoin2(char *line, char *buffer);
int					ft_strchar(char *str, char c);
void				ft_index(char *buffer);
char				*ft_clean(char *line);
int					ft_strlen2(char *str);
char				*filed(char *line);

#endif
