/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:29:15 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/29 02:05:48 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_double_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
}

int	error_msg(char *err, int fd)
{
	ft_putstr_fd(err, fd);
	exit(0);
}

int	check_numbers_args(int n, int i, char **str)
{
	i++;
	while (str[i])
	{
		if (ft_atoi(str[i]) == n)
			return (true);
		i++;
	}
	return (false);
}

int	check_if_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == ' ')
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	full_args_check(char **av)
{
	int		i;
	char	**full_arg;
	long	num_check;

	i = 0;
	full_arg = av;
	while (full_arg[i])
	{
		num_check = ft_atoi(full_arg[i]);
		if (check_if_number(full_arg[i]) == 0)
			error_msg("Error", 2);
		if (check_numbers_args(num_check, i, full_arg))
			error_msg("Error", 2);
		if (num_check < LONG_NEG || num_check > LONG_POS)
			error_msg("Error", 2);
		i++;
	}
}
