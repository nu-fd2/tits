/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:12:07 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/19 17:20:55 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

size_t		ft_strlen(const char *who);//
size_t		ft_strlcpy(char *dst, const char *src, size_t n);//
size_t		ft_strlcat(char *dst, const char *src, size_t n);//

// int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memset(void	*ptr, int n, size_t num);//
void		ft_bzero(void *s, size_t len);//
// void		*ft_memcpy(void *dst, const void *src, size_t n);
// void		*ft_memmove(void *dst, const void *src, size_t len);
// void		*ft_memchr(const void *s, int c, size_t n);

// int			ft_isalpha(int c);
int			ft_isdigit(int c);//
// int			ft_isalnum(int c);
// int			ft_isascii(int c);
// int			ft_isprint(int c);
// int			ft_toupper(int c);
// int			ft_tolower(int c);

int			ft_strncmp(const char *s1, const char *s2, size_t n);//
int			ft_strcmp(const char *s1, const char *s2);//
char		*ft_strchr(const char *str, int c);//
// char		*ft_strrchr(const char *str, int c);
// char		*ft_strnstr(const char *haystack, const char *needle, size_t n);

int			ft_atoi(const char *str);//
char		*ft_itoa(int n);//

char		*ft_strdup(const char *s1);//
// char		*ft_strndup(const char *s1, size_t n);
char		**ft_ssplit(char const *s, char c);//
void		*ft_calloc(size_t count, size_t size);//

char		*ft_ssubstr(char const *s, unsigned int start, size_t len);//
char		*ft_sstrjoin(char const *s1, char const *s2);//
// char		*ft_strtrim(char const *s1, char const *set);
// void		ft_striteri(char *s, void (*f)(unsigned int, char*));

// char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));

void		ft_putchar_fd(char c, int fd);//
void		ft_putstr_fd(char *s, int fd);//
// void		ft_putendl_fd(char *s, int fd);
// void		ft_putnbr_fd(int n, int fd);

// int			ft_lstsize(t_list *lst);
// void		ft_lstadd_front(t_list **lst, t_list *new);
// void		ft_lstadd_back(t_list **lst, t_list *new);
// void		ft_lstdelone(t_list *lst, void (*del)(void *));
// void		ft_lstclear(t_list **lst, void (*del)(void *));
// void		ft_lstiter(t_list *lst, void (*f)(void *));
// t_list		*ft_lstnew(void *content);
// t_list		*ft_lstlast(t_list *lst);
// t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif		//LIBFT_H
