/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:05:58 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/12 21:02:49 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *m_str, const char *sub_str, size_t size)
{
	size_t	i;
	size_t	j;

	if (*sub_str == '\0')
		return ((char *)m_str);
	i = 0;
	while (m_str[i] != '\0' && i < size)
	{
		if (m_str[i] == *sub_str)
		{
			j = 0;
			while (sub_str[j] != '\0' && j + i < size)
			{
				if (m_str[i + j] == sub_str[j] && sub_str[j + 1] == '\0')
					return ((char *)m_str + i);
				else if (m_str[i + j] != sub_str[j])
					break ;
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
