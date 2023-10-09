/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_any_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:25:59 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/17 10:40:43 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_print_base_sign(long long num, char *base)
{
	int	print_len;

	print_len = 0;
	if (num < 0)
	{
		print_len += ft_putchar('-');
		num *= -1;
	}
		print_len += ft_print_base_uns(num, base);
	return (print_len);
}

int	ft_print_base_uns(unsigned long num, char *base)
{
	int				print_len;
	unsigned long	base_len;
	int				p;

	print_len = 0;
	base_len = ft_strlen(base);
	if (num >= base_len)
		print_len += ft_print_base_uns(num / base_len, base);
	p = ft_putchar(base[num % base_len]);
	if (p < 0)
		return (-1);
	print_len++;
	return (print_len);
}
