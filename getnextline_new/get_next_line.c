/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:40:37 by mmezzat           #+#    #+#             */
/*   Updated: 2023/02/25 23:48:38 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_concat_free(char *buf1, char *buf2)
{
	char	*holder;

	holder = ft_strjoin(buf1, buf2);
	free_str_mem(&buf1);
	if (!holder)
		return (NULL);
	return (holder);
}

char	*extract_previous_line(char *buffer)
{
	int		i;
	int		j;
	size_t	buf_len;
	char	*extracted_line_buff;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free_str_mem(&buffer));
	buf_len = (ft_strlen(buffer) - i) + 1;
	extracted_line_buff = ft_calloc(sizeof(char), buf_len);
	if (!extracted_line_buff)
		return (free_str_mem(&buffer));
	i++;
	j = 0;
	while (buffer[i])
		extracted_line_buff[j++] = buffer[i++];
	free_str_mem(&buffer);
	return (extracted_line_buff);
}

char	*read_one_line_first(char *buffer)
{
	char	*return_line;
	int		i;
	int		count;

	count = 0;
	if (!buffer || !buffer[count])
		return (NULL);
	while (buffer[count] && buffer[count] != '\n')
		count++;
	if (buffer[count] == '\n')
		count++;
	return_line = ft_calloc(sizeof(char), (count + 1));
	if (!return_line)
		return (free_str_mem(&return_line));
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		return_line[i] = buffer[i];
	if (buffer[i] && buffer[i] == '\n')
		return_line[i] = '\n';
	return (return_line);
}

char	*read_file(int fd, char *buff_res)
{
	char	*buffer;
	int		b_read;

	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!buff_res)
		buff_res = ft_calloc(1, 1);
	if (!buff_res)
		return (free(buffer), NULL);
	b_read = 424;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (free(buffer), NULL);
		buffer[b_read] = '\0';
		buff_res = ft_concat_free(buff_res, buffer);
		if (!buff_res)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), buff_res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*return_line;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		if (read(fd, 0, 0) < 0)
			return (NULL);
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	return_line = read_one_line_first(buffer);
	if (!return_line)
		return (free_str_mem(&buffer));
	buffer = extract_previous_line(buffer);
	return (return_line);
}
