/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:07:22 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/05/08 15:02:32 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"

# define FT_MIN(A, B)	(((A) < (B)) ? (A) : (B))
# define FT_MAX(A, B)	(((A) > (B)) ? (A) : (B))

# define FT_ABS(X)		(size_t)(((X) < 0) ? (-(X)) : (X))
# define FT_POW(X)		(X * X)

# define FT_ULONG_MAX	((unsigned long)(~0L))
# define FT_LONG_MAX	((long)(FT_ULONG_MAX >> 1))
# define FT_LONG_MIN	((long)(~FT_LONG_MAX))

# define FT_UINT_MAX	((unsigned)(~0L))
# define FT_INT_MAX		((int)(FT_UINT_MAX >> 1))
# define FT_INT_MIN		((int)(~FT_INT_MAX))

# define FT_UCHAR_MAX	((unsigned char)(~0L))
# define FT_CHAR_MAX	((char)(FT_UCHAR_MAX >> 1))
# define FT_CHAR_MIN	((char)(~FT_CHAR_MAX))

# define INDEX(X)		((X) - 1)

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
**	Memory
*/
void			*ft_memset(void *memptr, int val, size_t num);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void			*ft_memccpy(void *des, const void *src, int ch, size_t count);
void			*ft_memmove(void *destptr, const void *srcptr, size_t num);
void			*ft_memchr(const void *memptr, int val, size_t num);
int				ft_memcmp(const void *memptr1, const void *memptr2, size_t num);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

/*
**	String
*/
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strcat(char *destptr, const char *srcptr);
char			*ft_strncat(char *destptr, char *srcptr, size_t num);
size_t			ft_strlcat(char *destptr, const char *srcptr, size_t size);
char			*ft_strchr(const char *str, int val);
char			*ft_strrchr(const char *str, int val);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t num);
int				ft_atoi(const char *str);
double			ft_atof(const char *str);
t_bool			ft_isint(const char *str, t_bool strict);
int				ft_isalpha(int c);
int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strndup(const char *src, size_t size);
int				get_next_line(const int fd, char **line);

/*
**	Io
*/
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(int i);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
**	List
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *ne);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Extra func
*/
size_t			ft_wordcount(char const *str, char val);
void			ft_swap(void **a, void **b);
int				ft_lstcount(t_list *lst);
void			ft_lstaddback(t_list **list, void const *content,
				size_t content_size);
char			*ft_strlower(char *str);

#endif
