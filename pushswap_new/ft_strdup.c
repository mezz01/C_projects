/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:09:05 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/25 05:58:39 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
