/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:58:16 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/16 03:22:07 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_xpm(t_vars *mp)
{
	mp->plr = mlx_xpm_file_to_image(mp->minlx, "./xpm_file/sonic.xpm", \
	&mp->dt->width, &mp->dt->height);
	mp->cl = mlx_xpm_file_to_image(mp->minlx, "./xpm_file/yellow_circle.xpm", \
	&mp->dt->width, &mp->dt->height);
	mp->ext = mlx_xpm_file_to_image(mp->minlx, "./xpm_file/exit.xpm", \
	&mp->dt->width, &mp->dt->height);
	mp->wall = mlx_xpm_file_to_image(mp->minlx, "./xpm_file/wall.xpm", \
	&mp->dt->width, &mp->dt->height);
	mp->bckg = mlx_xpm_file_to_image(mp->minlx, "./xpm_file/background.xpm", \
	&mp->dt->width, &mp->dt->height);
	if (!mp->bckg || !mp->plr || !mp->cl || !mp->ext 
		|| !mp->wall)
		messg2();
}

void	convert_img_to_window(t_vars *mp)
{
	mp->y = -1;
	while (mp->strmap[++mp->y])
	{
		mp->x = -1;
		while (mp->strmap[mp->y][++mp->x])
		{
			mlx_put_image_to_window(mp->minlx, mp->minlx_window, \
				mp->bckg, mp->x * 32, mp->y * 32);
			if (mp->strmap[mp->y][mp->x] == '1')
				mlx_put_image_to_window(mp->minlx, mp->minlx_window, \
				mp->wall, mp->x * 32, mp->y * 32);
			if (mp->strmap[mp->y][mp->x] == 'C')
				mlx_put_image_to_window(mp->minlx, mp->minlx_window, \
				mp->cl, mp->x * 32, mp->y * 32);
			if (mp->strmap[mp->y][mp->x] == 'E')
				mlx_put_image_to_window(mp->minlx, mp->minlx_window, \
				mp->ext, mp->x * 32, mp->y * 32);
			if (mp->strmap[mp->y][mp->x] == 'P')
				mlx_put_image_to_window(mp->minlx, mp->minlx_window, \
				mp->plr, mp->x * 32, mp->y * 32);
		}
	}
}

int	exit_game(t_vars *mp)
{
	int	i;

	i = 0;
	while (mp->strmap[i] != NULL)
	{
		free(mp->strmap[i]);
		i++;
	}
	free(mp->strmap);
	mlx_destroy_image(mp->minlx, mp->plr);
	mlx_destroy_image(mp->minlx, mp->cl);
	mlx_destroy_image(mp->minlx, mp->ext);
	mlx_destroy_image(mp->minlx, mp->wall);
	mlx_destroy_image(mp->minlx, mp->bckg);
	mlx_destroy_window(mp->minlx, mp->minlx_window);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
