/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:41:15 by mmezzat           #+#    #+#             */
/*   Updated: 2023/02/25 23:51:47 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10003
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

char	*free_str_mem(char **to_free_str);
char	*ft_strjoin(char const *st1, char const *st2);
char	*ft_strchr(const char *str, int find_chr);
void	*ft_calloc(size_t block_size, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_concat_free(char *buf1, char *buf2);
char	*extract_previous_line(char *buffer);
char	*read_one_line_first(char *buffer);
char	*read_file(int fd, char *buff_res);
char	*get_next_line(int fd);

#endif