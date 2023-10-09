/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:45:07 by mmezzat           #+#    #+#             */
/*   Updated: 2023/06/13 00:25:38 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include<stdarg.h>

# define WAIT 700
# define BASE10 "0123456789"
# define BS16L "0123456789abcdef"
# define BASE16U "0123456789ABCDEF"

int		ft_printf(const char *print_form, ...);
int		ft_putchar(char s);
int		ft_printstr(char *s);
int		ft_strlen(char *s);
int		ft_print_base_sign(long long num, char *base);
int		ft_print_base_uns(unsigned long num, char *base);
int		ft_atoi(const char *ptr_str);
int		ft_isdigit(int chr);
void	sending_signal(int server_id, char c);
void	receiving_signal(int signal, siginfo_t *info, void *context);

#endif