/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:09:05 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/16 03:20:25 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	lenght;

	lenght = ft_strlen(str);
	ptr = (char *)malloc(lenght + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, str, lenght + 1);
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			src_len;
	unsigned int	i;

	i = 0;
	src_len = ft_strlen(src);
	if (size <= 0)
		return (src_len);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
