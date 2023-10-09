/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:27:47 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/15 18:52:09 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s_itr, char (*f)(unsigned int, char))
{
	unsigned int	s_i;
	char			*f_str;

	if (!s_itr || !f)
		return (0);
	f_str = (char *)malloc(sizeof(char) * (ft_strlen(s_itr) + 1));
	if (!f_str)
		return (0);
	s_i = 0;
	while (s_itr[s_i])
	{
		f_str[s_i] = f(s_i, s_itr[s_i]);
		s_i++;
	}
	f_str[s_i] = '\0';
	return (f_str);
}
