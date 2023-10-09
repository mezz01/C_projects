/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:54:36 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/16 03:16:01 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(t_vars *mp)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (mp->strmap[i])
	{
		j = 0;
		while (mp->strmap[i][j])
		{
			if (mp->strmap[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	mp->pl = player;
	if (player < 1 || player > 1)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	check_collectible(t_vars *mp)
{
	int	i;
	int	j;
	int	cltb;

	i = 0;
	cltb = 0;
	while (mp->strmap[i])
	{
		j = 0;
		while (mp->strmap[i][j])
		{
			if (mp->strmap[i][j] == 'C')
				cltb++;
			j++;
		}
		i++;
	}
	mp->c = cltb;
	if (cltb < 1)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	check_exit(t_vars *mp)
{
	int	i;
	int	j;
	int	ext;

	i = 0;
	ext = 0;
	while (mp->strmap[i])
	{
		j = 0;
		while (mp->strmap[i][j])
		{
			if (mp->strmap[i][j] == 'E')
				ext++;
			j++;
		}
		i++;
	}
	mp->ex = ext;
	if (ext < 1 || ext > 1)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	full_check(t_vars *mp)
{
	if (check_player(mp) == EXIT_FAILURE
		|| check_collectible(mp) == EXIT_FAILURE
		|| check_exit(mp) == EXIT_FAILURE)
	{
		write(2, "ERROR\nProblem in player, collectible or exit!\n", 47);
		return (EXIT_FAILURE);
	}
	else
		return (EXIT_SUCCESS);
}
