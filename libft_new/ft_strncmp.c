/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:43:20 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/11 16:57:57 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	ind;

	if (!s1 && !s2)
		return (0);
	ind = 0;
	while (ind < n)
	{
		if (s1[ind] == '\0' || s2[ind] == '\0')
			return ((unsigned char)s1[ind] - (unsigned char)s2[ind]);
		if (s1[ind] != s2[ind])
			return ((unsigned char)s1[ind] - (unsigned char)s2[ind]);
		ind++;
	}
	return (0);
}
