/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:04:26 by mmezzat           #+#    #+#             */
/*   Updated: 2023/06/13 00:26:13 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
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

int	ft_checkpercent(va_list p_args, char aft_prc_chr)
{
	int	print_len;

	print_len = 0;
	if (aft_prc_chr == '%')
		print_len += ft_putchar('%');
	else if (aft_prc_chr == 'c')
		print_len += ft_putchar(va_arg(p_args, int));
	else if (aft_prc_chr == 'u')
		print_len += ft_print_base_uns(va_arg(p_args, unsigned int), BASE10);
	else if (aft_prc_chr == 'x')
		print_len += ft_print_base_uns(va_arg(p_args, unsigned int), BS16L);
	else if (aft_prc_chr == 'X')
		print_len += ft_print_base_uns(va_arg(p_args, unsigned int), BASE16U);
	else if (aft_prc_chr == 'p')
	{
		print_len += (ft_printstr("0x")
				+ ft_print_base_uns(va_arg(p_args, unsigned long int), BS16L));
	}
	else if (aft_prc_chr == 'd' || aft_prc_chr == 'i')
		print_len += ft_print_base_sign(va_arg(p_args, int), BASE10);
	else if (aft_prc_chr == 's')
		print_len += ft_printstr(va_arg(p_args, char *));
	else
		print_len += ft_putchar(aft_prc_chr);
	return (print_len);
}

int	ft_printf(const char *print_form, ...)
{
	int		id;
	va_list	print_list;
	int		print_len;

	id = 0;
	print_len = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(print_list, print_form);
	while (print_form[id])
	{
		if (print_form[id] == '%')
		{
			id++;
			if (print_form[id] == '\0')
				break ;
			print_len += ft_checkpercent(print_list, print_form[id]);
		}
		else
			print_len += ft_putchar(print_form[id]);
		id++;
	}
	va_end(print_list);
	return (print_len);
}
