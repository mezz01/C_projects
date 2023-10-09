/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:57:04 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/16 08:30:34 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_height(char **mp)
{
	int	height;

	height = 0;
	while (mp[height])
		height++;
	return (height);
}

int	ft_width(char **mp)
{
	int	width;

	width = ft_strlen(mp[0]);
	return (width);
}

int	check_if_big(char **mp)
{
	int	i;
	int	j;

	i = ft_height(mp);
	j = ft_width(mp);
	if (i > 164 || j > 165)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_walls(char **mp)
{
	int	x;
	int	y;
	int	height;
	int	width;

	y = -1;
	height = ft_height(mp) - 1;
	width = ft_width(mp) - 1;
	while (mp[++y])
	{
		x = -1;
		while (mp[y][++x])
		{
			if (mp[0][x] != '1' || mp[y][0] != '1' || mp[y][width] != '1'
				|| mp[height][x] != '1')
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	check_if_perfect(char **mp)
{
	if (check_if_big(mp) == EXIT_FAILURE)
		messg1();
	if (check_walls(mp) == EXIT_FAILURE)
	{
		write(2, "ERROR\nProblem with walls!\n", 27);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
