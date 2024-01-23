/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:53:07 by jsauveur          #+#    #+#             */
/*   Updated: 2023/12/17 22:52:00 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*LIBFT*/
float	find_sign(float nb_float);
int		ft_atoi(const char *s);
bool	ft_isdigit(int c);
bool	ft_isprint(int c);
bool	ft_isspace(char c);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
bool	str_isdigit(char *str);

/*GET_NEXT_LINE*/
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

/*PRINTF*/
int		ft_printf(const char *format, ...);
int		ft_printbase(const char *format, int len, va_list args);
int		ft_putstr(char *s);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_unsign(unsigned int nb);
int		ft_upperhex(unsigned int n);
int		ft_lowerhex(unsigned long n);
int		ft_point(unsigned long nb);

#endif
