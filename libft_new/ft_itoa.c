/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:22:40 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/14 17:40:48 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_intsize(long num)
{
	size_t	i;

	i = 0;
	if (num == 0)
	{
		i++;
		return (i);
	}
	if (num < 0)
	{
		num = num * -1;
		i++;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*pointer;
	size_t	num_len;
	long	num;

	num = n;
	num_len = ft_intsize(num);
	pointer = (char *)malloc(sizeof(char) * num_len + 1);
	if (!pointer)
		return (0);
	pointer[num_len--] = '\0';
	if (n == 0)
		pointer[0] = '0';
	if (num < 0)
	{
		pointer[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		pointer[num_len] = (num % 10) + '0';
		num = num / 10;
		num_len--;
	}
	return (pointer);
}
