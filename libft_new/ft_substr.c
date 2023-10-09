/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:00:54 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/08 20:04:03 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *str, unsigned int index, size_t sub_max)
{
	char	*sub_str;
	size_t	p;

	if (!str)
		return (NULL);
	if (!sub_max || index >= ft_strlen(str))
		return (ft_strdup(""));
	p = ft_strlen(str) - index;
	if (p > sub_max)
	p = sub_max;
	p += 1;
	sub_str = (char *)malloc(sizeof(char) * (p));
	if (!sub_str)
		return (0);
	ft_strlcpy(sub_str, str + index, p);
	return (sub_str);
}
