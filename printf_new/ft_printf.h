/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:16:04 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/17 13:48:41 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE10 "0123456789"
# define BS16L "0123456789abcdef"
# define BASE16U "0123456789ABCDEF"

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>

int	ft_printf(const char *print_form, ...);
int	ft_putchar(char s);
int	ft_printstr(char *s);
int	ft_strlen(char *s);
int	ft_print_base_sign(long long num, char *base);
int	ft_print_base_uns(unsigned long num, char *base);

#endif