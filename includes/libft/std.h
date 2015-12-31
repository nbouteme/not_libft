/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:20:53 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/09 15:55:25 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef t_list		*(*t_genup)		(t_list *, void *);
typedef void		(*t_afup)		(t_list *, const t_list *, void*);
typedef t_list		*(*t_gen)		(t_list *);
typedef void		(*t_af)			(t_list *, const t_list *);
typedef void		(*t_destructor)	(void *, size_t);
typedef void		(*t_striteri)	(unsigned int, char *);
typedef void		(*t_iterup)		(t_list *, void *);
typedef void		(*t_iter)		(t_list *);
typedef void		(*t_striter)	(char *);
typedef char		(*t_strmapi)	(unsigned int, char);
typedef char		(*t_strmap)		(char);
typedef int			(*t_strmapw)	(int);
typedef int			(*t_lstcmpup)	(const t_list *, const t_list *, void *);
typedef int			(*t_lstcmp)		(const t_list *, const t_list *);
typedef int			(*t_keepup)		(t_list *, void *);
typedef int			(*t_keep)		(t_list *);
typedef const t_list t_clist;

t_list				*ft_lstreduceup(t_clist *l, t_clist *init, t_afup f, void *up);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
void				ft_lstsortup(t_list **head, t_lstcmpup cmp, void *up);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
t_list				*ft_lstfilterup(t_list *lst, t_keepup f, void *up);
char				*ft_strncpy(char *dst, const char *src, size_t n);
t_list				*ft_lstnewown(void *content, size_t content_size);
void				ft_lstsplit(t_list *head, t_list **a, t_list **b);
t_list				*ft_lstreduce(t_clist *l, t_clist *init, t_af f);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
void				ft_lstiterup(t_list *lst, t_iterup f, void *up);
void				ft_lstdelone(t_list **alst, t_destructor del);
t_list				*ft_lstmapup(t_list *l, t_genup f, void *up);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_swap_any(void *a, void *b, size_t size);
void				ft_lstdel(t_list **alst, t_destructor del);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_lstpush(t_list **lst, t_list *to_add);
char				*ft_luitoa(unsigned long n, char *base);
void				ft_lstsort(t_list **head, t_lstcmp cmp);
char				*ft_strmapi(char const *s, t_strmapi f);
char				*ft_strmapw(char const *s, t_strmapw f);
char				*ft_strcpy(char *dst, const char *src);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strmap(char const *s, t_strmap f);
void				ft_lstadd(t_list **alst, t_list *new);
char				**ft_strtok(const char *str, char c);
int					ft_strindexof(const char *n, char c);
char				*ft_strcat(char *s1, const char *s2);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstfilter(t_list *lst, t_keep f);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_striteri(char *s, t_striteri f);
char				*ft_strrchr(const char *s, int c);
void				ft_lstiter(t_list *lst, t_iter f);
char				*ft_strchr(const char *s, int c);
t_list				*ft_lstmap(t_list *lst, t_gen f);
void				ft_striter(char *s, t_striter f);
char				*ft_lsitoa(long n, char *base);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_bzero(void *s, size_t n);
char				*ft_strtrim(char const *s);
char				*ft_strdup(const char *s);
void				ft_putendl(char const *s);
void				*ft_memalloc(size_t size);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
void				ft_putstr(char const *s);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
char				*ft_strrev(char *s);
void				ft_strclr(char *s);
void				ft_putchar(char c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
void				ft_putnbr(int n);
char				*ft_itoa(int n);

#endif
