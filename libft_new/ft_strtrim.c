/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:04:21 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/11 17:10:19 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *totrim_s, char const *trim_c)
{
	size_t	s_len;
	char	*trimed_s;

	if (!totrim_s || !trim_c)
		return (0);
	while (ft_strchr(trim_c, *totrim_s) && *totrim_s != '\0')
		totrim_s++;
	if (*totrim_s == '\0')
		return (ft_strdup(""));
	s_len = ft_strlen(totrim_s);
	while (ft_strchr(trim_c, totrim_s[s_len]))
		s_len--;
	trimed_s = ft_substr(totrim_s, 0, s_len + 1);
	return (trimed_s);
}
