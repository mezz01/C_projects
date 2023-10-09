/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:10:47 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/25 22:41:35 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *ptr_str)
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
	while (ptr_str[i] && ptr_str[i] <= '9' && ptr_str[i] >= '0')
	{
		check_num = s_num;
		s_num = (s_num * 10) + ptr_str[i++] - '0';
	}
	return (s_num * num_sign);
}
