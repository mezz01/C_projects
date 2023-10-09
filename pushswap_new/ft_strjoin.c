/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:10:50 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/26 22:12:50 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*return_str;
	int		i_s1;
	int		i_s2;

	return_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ 1));
	if (!return_str)
		return (0);
	i_s1 = 0;
	while (s1[i_s1])
	{
		return_str[i_s1] = s1[i_s1];
		i_s1++;
	}
	i_s2 = 0;
	while (s2[i_s2])
	{
		return_str[i_s1 + i_s2] = s2[i_s2];
		i_s2++;
	}
	return_str[i_s1 + i_s2] = '\0';
	return (return_str);
}
