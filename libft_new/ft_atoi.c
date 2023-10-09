/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:10:47 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/14 17:26:59 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
