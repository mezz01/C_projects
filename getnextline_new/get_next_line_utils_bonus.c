/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:35:25 by mmezzat           #+#    #+#             */
/*   Updated: 2023/02/24 23:35:45 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_str_mem(char **to_free_str)
{
	if (to_free_str && *to_free_str)
	{
		free(*to_free_str);
		*to_free_str = NULL;
	}
	return (NULL);
}

char	*ft_strjoin(char const *st1, char const *st2)
{
	char	*concat_str;
	int		i;
	int		j;
	size_t	st_lenght;

	if (!st1 || !st2)
		return (NULL);
	i = -1;
	st_lenght = ft_strlen(st1);
	st_lenght += ft_strlen(st2);
	concat_str = ft_calloc(sizeof(char), (st_lenght + 1));
	if (!concat_str)
		return (NULL);
	while (st1[++i] != 0)
		concat_str[i] = st1[i];
	j = -1;
	while (st2[++j] != 0)
		concat_str[i + j] = st2[j];
	concat_str[i + j] = 0;
	return (concat_str);
}

char	*ft_strchr(const char *str, int find_chr)
{
	char	*return_str;

	return_str = (char *)str;
	while (*return_str != find_chr && *return_str != 0)
		return_str++;
	if (*return_str == find_chr)
		return (return_str);
	else
		return (NULL);
}

void	*ft_calloc(size_t block_size, size_t len)
{
	char	*return_str;
	size_t	byte;

	byte = block_size * len;
	return_str = malloc(byte);
	if (!return_str)
		return (NULL);
	while (byte > 0)
		return_str[--byte] = '\0';
	return_str[byte] = '\0';
	return (return_str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
