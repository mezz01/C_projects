/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 22:22:03 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/15 19:25:04 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>

int		ft_atoi(const char *ptr_str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n_blocks, size_t size_block);
int		ft_isalnum(int chr);
int		ft_isalpha(int chr);
int		ft_isascii(int chr);
int		ft_isdigit(int chr);
int		ft_isprint(int chr);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *p, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
void	ft_striteri(char *itr_s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *st);
char	*ft_strmapi(char const *s_itr, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *m_str, const char *sub_str, size_t size);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *totrim_s, char const *trim_c);
char	*ft_substr(char const *str, unsigned int index, size_t sub_max);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif