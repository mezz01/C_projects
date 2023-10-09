/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:59:26 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/16 08:59:55 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_background(char **actvmap)
{
	int	x;
	int	y;

	x = -1;
	while (actvmap[++x])
	{
		y = -1;
		while (actvmap[x][++y])
		{
			if (actvmap[x][y] == '0' && (actvmap[x][y + 1] == 'P'
				|| actvmap[x][y - 1] == 'P' || actvmap[x + 1][y] == 'P'
				|| actvmap[x - 1][y] == 'P'))
				return (1);
			else if (actvmap[x][y] == 'C' && (actvmap[x][y + 1] == 'P'
				|| actvmap[x][y - 1] == 'P' || actvmap[x + 1][y] == 'P'
				|| actvmap[x - 1][y] == 'P'))
				return (1);
		}
	}
	return (0);
}

void	place_p_instead(char **actvmap)
{
	int	x;
	int	y;

	x = -1;
	while (actvmap[++x])
	{
		y = -1;
		while (actvmap[x][++y])
		{
			if (actvmap[x][y] == '0' && (actvmap[x][y + 1] == 'P'
				|| actvmap[x][y - 1] == 'P' || actvmap[x + 1][y] == 'P'
				|| actvmap[x - 1][y] == 'P'))
				actvmap[x][y] = 'P';
			else if (actvmap[x][y] == 'C' && (actvmap[x][y + 1] == 'P'
				|| actvmap[x][y - 1] == 'P' || actvmap[x + 1][y] == 'P'
				|| actvmap[x - 1][y] == 'P'))
				actvmap[x][y] = 'P';
		}
	}
}

int	is_there_exit(char **actvmap)
{
	int	x;
	int	y;

	x = -1;
	while (actvmap[++x])
	{
		y = -1;
		while (actvmap[x][++y])
		{
			if (actvmap[x][y] == 'E' && (actvmap[x][y + 1] == 'P'
				|| actvmap[x][y - 1] == 'P' || actvmap[x + 1][y] == 'P'
				|| actvmap[x - 1][y] == 'P'))
				return (1);
		}
	}
	return (0);
}

int	check_all_cltb(char **actvmap)
{
	int	x;
	int	y;

	x = -1;
	while (actvmap[++x])
	{
		y = -1;
		while (actvmap[x][++y])
		{
			if (actvmap[x][y] == 'C')
				return (0);
		}
	}
	return (1);
}

int	solvable_map(char **actvmap)
{
	while (check_background(actvmap) == 1)
		place_p_instead(actvmap);
	if (is_there_exit(actvmap) == 1 && check_all_cltb(actvmap) == 1)
		return (1);
	else
	{
		write(2, "ERROR\npath error!\n", 19);
		return (0);
	}
}
