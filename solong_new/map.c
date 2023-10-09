/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:02:54 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/16 03:13:26 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(char *s, char **dim_str, t_vars *mp)
{
	int	i;

	i = -1;
	while (s[++i])
		write(2, &s[i], 1);
	free_two_maps(dim_str, mp);
	exit(EXIT_FAILURE);
}

int	check_enter_in_map(char *s, char **map)
{
	int	i;
	int	string_nl;
	int	map_line;

	i = -1;
	string_nl = 0;
	map_line = 0;
	while (s[++i])
	{
		if (s[i] == '\n')
			string_nl++;
	}
	i = -1;
	while (map[++i])
		map_line++;
	if (map_line <= string_nl)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char	**get_map(int f, t_vars *mp)
{
	char	*s;
	char	*s2;
	char	**dim_str;
	char	*tmp;

	s = ft_strdup("");
	s2 = get_next_line(f);
	while (s2 != 0)
	{
		tmp = s;
		s = ft_strjoin(s, s2);
		free(tmp);
		free(s2);
		s2 = get_next_line(f);
	}
	dim_str = ft_split(s, '\n');
	mp->active_strmap = ft_split(s, '\n');
	if (check_enter_in_map(s, dim_str) == 1)
		print_err("Error\nNew Line\n", dim_str, mp);
	free(s);
	free(s2);
	if (dim_str[0] == 0)
		print_err("ERROR\nEmpty map\n", dim_str, mp);
	return (dim_str);
}

void	locate_player(t_vars *mp)
{
	int	x;
	int	y;

	y = 0;
	while (mp->strmap[y])
	{
		x = 0;
		while (mp->strmap[y][x])
		{
			if (mp->strmap[y][x] == 'P')
			{
				mp->plyr_x = x;
				mp->plyr_y = y;
			}
			x++;
		}
		y++;
	}
}
