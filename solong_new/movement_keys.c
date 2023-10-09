/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:28:09 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/16 09:38:51 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_move(t_vars *mp)
{
	if (mp->strmap[mp->plyr_y][mp->plyr_x] == 'P')
	{
		if ((mp->strmap[mp->plyr_y - 1][mp->plyr_x] == '0'
			|| mp->strmap[mp->plyr_y - 1][mp->plyr_x] == 'C'))
		{
			if (mp->strmap[mp->plyr_y - 1][mp->plyr_x] == 'C')
			{
				mp->c--;
			}
			mp->strmap[mp->plyr_y - 1][mp->plyr_x] = 'P';
			mp->strmap[mp->plyr_y][mp->plyr_x] = '0';
			mp->moves_display++;
		}
		if (mp->c == 0 && mp->strmap[mp->plyr_y - 1][mp->plyr_x] == 'E')
			exit(write(2, "You won!\n", 10));
	}
}

void	right_move(t_vars *mp)
{
	if (mp->strmap[mp->plyr_y][mp->plyr_x] == 'P')
	{
		if ((mp->strmap[mp->plyr_y][mp->plyr_x + 1] == '0'
			|| mp->strmap[mp->plyr_y][mp->plyr_x + 1] == 'C'))
		{
			if (mp->strmap[mp->plyr_y][mp->plyr_x + 1] == 'C')
			{
				mp->c--;
			}
			mp->strmap[mp->plyr_y][mp->plyr_x + 1] = 'P';
			mp->strmap[mp->plyr_y][mp->plyr_x] = '0';
			mp->moves_display++;
		}
		if (mp->c == 0 && mp->strmap[mp->plyr_y][mp->plyr_x + 1] == 'E')
			exit(write(2, "You won!\n", 10));
	}
}

void	down_move(t_vars *mp)
{
	if (mp->strmap[mp->plyr_y][mp->plyr_x] == 'P')
	{
		if ((mp->strmap[mp->plyr_y + 1][mp->plyr_x] == '0'
			|| mp->strmap[mp->plyr_y + 1][mp->plyr_x] == 'C'))
		{
			if (mp->strmap[mp->plyr_y + 1][mp->plyr_x] == 'C')
			{
				mp->c--;
			}
			mp->strmap[mp->plyr_y + 1][mp->plyr_x] = 'P';
			mp->strmap[mp->plyr_y][mp->plyr_x] = '0';
			mp->moves_display++;
		}
		if (mp->c == 0 && mp->strmap[mp->plyr_y + 1][mp->plyr_x] == 'E')
			exit(write(2, "You won!\n", 10));
	}
}

void	left_move(t_vars *mp)
{
	if (mp->strmap[mp->plyr_y][mp->plyr_x] == 'P')
	{
		if ((mp->strmap[mp->plyr_y][mp->plyr_x - 1] == '0'
			|| mp->strmap[mp->plyr_y][mp->plyr_x - 1] == 'C'))
		{
			if (mp->strmap[mp->plyr_y][mp->plyr_x - 1] == 'C')
			{
				mp->c--;
			}
			mp->strmap[mp->plyr_y][mp->plyr_x - 1] = 'P';
			mp->strmap[mp->plyr_y][mp->plyr_x] = '0';
			mp->moves_display++;
		}
		if (mp->c == 0 && mp->strmap[mp->plyr_y][mp->plyr_x - 1] == 'E')
			exit(write(2, "You won!\n", 10));
	}
}
