/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_any_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:44:10 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/16 23:40:56 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putchar(char s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
