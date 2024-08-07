/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:09:06 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/07/03 19:15:18 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 10
# define BUFFER_SIZE 1
# define OPEN_MAX	FOPEN_MAX
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <string.h>

typedef struct t_list
{
	void			*content;
	struct t_list	*next;
}	t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_strlen(const char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_isprint(int c);
int				ft_toupper(int c);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, char c);
char			*ft_strrchr(const char *str, char c);
int				ft_strncmp(const char *s1, char *s2, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *str, char c);
char			*ft_itoa(int n);
void			ft_add_str(char *str, char character);
unsigned int	ft_num_size(int num);
char			*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void			ft_striteri(char *str, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_putchar(char c);
long long int	ft_atol(const char *str);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcat(char *dest, const char *src);
int				ft_strcmpc(const char *s1, const char *s2, char c);
char			*ft_strswap(char *dst, char *src, char *sub);
int				ft_is_enter(char *str);
int				ft_isspace(char c);
int				ft_strcmpnks(char *s1, char *s2);
int				ft_isnum(char c);

// get_next_line.c
char			*get_next_line(int fd);
char			*readbuf(int fd, char *str);
char			*n_line(char *str);
char			*clean_storage(char *str);
char			*ft_free(char **str);

// get_next_line_utils.c
char			*ft_strjoin_gnl(char *s1, char *s2);
size_t			ft_strl(char *str);
char			*ft_strchr(const char *s, char c);
char			*ft_substr_gnl(char *s, unsigned int start, size_t l);
char			*ft_strncpy(char *dest, const char *src, size_t n);

#endif
