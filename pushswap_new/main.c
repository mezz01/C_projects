/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 05:09:25 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/29 09:24:40 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_stacks(int c, char **v)
{
	t_node	*a;
	int		i;

	(void)c;
	a = NULL;
	i = 0;
	while (v[i])
	{
		add_node_to_stack(&a, new_node(ft_atoi(v[i])));
		i++;
	}
	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
	create_indexes(&a);
	return (a);
}

int	count_space(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

int	empty_string(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0)
			return (1);
		if ((size_t)count_space(av[i]) == ft_strlen(av[i]))
			return (1);
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (!ft_isdigit(av[i][j + 1]))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**complete_string(int ac, char **av)
{
	int		i;
	char	*s;
	char	*tmp;
	char	**t;

	i = ac - 1;
	tmp = malloc(1);
	while (i)
	{
		s = ft_strjoin(av[i], tmp);
		free(tmp);
		tmp = s;
		s = ft_strjoin(" ", tmp);
		free(tmp);
		tmp = s;
		i--;
	}
	t = ft_split(s, ' ');
	free(s);
	return (t);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	**t;

	b = NULL;
	if (empty_string(av))
	{
		ft_putstr_fd("Error", 2);
		return (1);
	}
	if (ac < 2)
		return (0);
	t = complete_string(ac, av);
	full_args_check(t);
	a = create_stacks(ac, t);
	if (check_if_sorted(&a))
	{
		stack_free(&a);
		stack_free(&b);
		return (0);
	}
	early_sort(&a, &b);
	stack_free(&a);
	stack_free(&b);
	return (0);
}
