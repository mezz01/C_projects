/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:58:59 by mmezzat           #+#    #+#             */
/*   Updated: 2023/06/12 17:59:24 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int chr)
{
	if (chr >= '0' && chr <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *ptr_str)
{
	int			i;
	long long	num_sign;
	long long	s_num;
	long long	check_num;

	i = 0;
	s_num = 0;
	num_sign = 1;
	while (ptr_str[i] == ' ' || (ptr_str[i] >= '\t' && ptr_str[i] <= '\r'))
		i++;
	if (ptr_str[i] == '-' || ptr_str[i] == '+')
	{
		if (ptr_str[i++] == '-')
			num_sign *= -1;
	}
	while (ft_isdigit(ptr_str[i]) && ptr_str[i])
	{
		check_num = s_num;
		s_num = (s_num * 10) + ptr_str[i++] - '0';
		if (check_num != (s_num / 10) && num_sign == 1)
			return (-1);
		if ((s_num / 10) != check_num && num_sign == -1)
			return (0);
	}
	return (s_num * num_sign);
}

int	ft_putchar(char s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
