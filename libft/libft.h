/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:18:06 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/22 13:28:11 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

/*
**	Types.
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
**	Output.
*/

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);

/*
**	Memory.
*/

void			*ft_memset(void *ptr, int value, size_t num);
void			*ft_memcpy(void *dst, const void *src, size_t num);
void			ft_bzero(void *s, int n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t num);
void			*ft_memchr(const void *ptr, int value, size_t num);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

/*
**	String.
*/

size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, unsigned int n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_strdup(const char *src);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, int nb);
size_t			ft_strlcat(char *dest, const char *src, unsigned int size);
char			*ft_strchr(const char *str, int character);
char			*ft_strrchr(const char *str, int character);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *big, const char *little, size_t len);

int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isascii(int c);

int				ft_tolower(int c);
int				ft_toupper(int c);

int				ft_atoi(const char *str);
char			*ft_itoa(int n);

/*
**	Non libc.
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

void			ft_strclr(char *s);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *str, char c);

/*
**	List functions.
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**	Linq-like functions.
*/

void			ft_foreach(void *ptr, int size, int step, void (f)(void*));
int				ft_any(void *ptr, int size, int step, int (f)(void*));
int				ft_all(void *ptr, int size, int step, int (f)(void*));
int				ft_min(int *ptr, int size);
int				ft_max(int *ptr, int size);

#endif
