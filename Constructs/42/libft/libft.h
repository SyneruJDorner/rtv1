/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 09:19:13 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:00:44 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define TRUE (1 == 1)
# define FALSE (!TRUE)
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_wrdcount(char const *s, char c);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memcpy(void *destination, const void *source, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *str, int c, size_t len);
char			*ft_strcat(char *destination, const char *source);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strcpy(char *destination, const char *source);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *destination, const char *source, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strncat(char *destination, const char *source, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *destination, const char *source, size_t n);
char			*ft_strnstr(const char *sentence,
							const char *pattern, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *sentence, const char *pattern);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memccpy(void *dst, const void *src, int charc, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_putstr(char const *str);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void(*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinfree(char *s1, char *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putlst(t_list *lst);
char			*ft_itoa(int n);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstfree(t_list *lst);
void			ft_lstrev(t_list **lst);
int				ft_lstcount(t_list *lst);
t_list			*ft_lst_ignorecomments(t_list *lst,
				char *start_comment, char *end_comment);
double			ft_abs(double nbr);
double			ft_max(int a, int b);
double			ft_min(int a, int b);
int				ft_rm_char(char *dest, char c);

#endif
