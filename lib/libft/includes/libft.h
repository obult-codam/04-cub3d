/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Ivellinga <izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 21:12:35 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/09/22 18:42:39 by ivelling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

# ifndef MAX_MIN_INT
#  define MAX_MIN_INT -2147483648
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *str1, const char *str2, size_t n);
int					ft_strncmp(const char *str1, const char *str2, size_t n);

int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_iswhitespace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(const char *s1, const char *set);
char				**ft_split(const char *str, char c);
char				*ft_itoa(int n);
char				*ft_malloc_less_itoa(int n);
char				*ft_uns_itoa(unsigned int n);
int					ft_long_atoi(long *out, const char *str);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				error(int fd);
void				error_and_msg(const char *str, int fd);
void				exit_msg(const char *str, int fd);
void				double_exit_msg(const char *str, const char *str1, int fd);
void				my_perror_exit(char *progname, const char *arg, int fd);
int					extention_check(char *str, char *ext);
void				print_2d_array(char **arr);
void				free_2d_array(char **arr);
void				free_3d_array(char ***arr);
char				*join_3_strings(const char *str0, const char *str1, \
	const char *str2);
int					arr_len(char **str);

/* Get_next_line. some slightly altered basic functions and
	two defines relevant for GNL*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef MAX_FD
#  define MAX_FD 100000
# endif

int					get_next_line(int fd, char **line);
int					gnl_strlen(char *str);
void				*gnl_calloc(size_t count, size_t size);
char				*gnl_strjoin(char *str1, char *str2);
int					gnl_free_all(char **buff, char **line, int fd);
int					final_line(char *buff, int newline_index, char **line);

#endif
