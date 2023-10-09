/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:50:29 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/15 15:01:09 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_striteri(char *itr_s, void (*f)(unsigned int, char *))
{
	int	s_i;

	s_i = 0;
	if (!f || !itr_s)
		return ;
	while (itr_s[s_i])
	{
		f(s_i, &itr_s[s_i]);
		s_i++;
	}
}
