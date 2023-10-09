/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:36:32 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/16 09:35:59 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_display_msg(void)
{
	exit(write(2, "You won!\n", 10));
}

int	check_keys(int key_num, t_vars *mp)
{
	int	nmoves;

	if (key_num == ESC_KEY)
		exit_game(mp);
	locate_player(mp);
	nmoves = mp->moves_display;
	if (key_num == UP_KEY || key_num == UP_KEY2)
	{
		up_move(mp);
	}
	if (key_num == RIGHT_KEY || key_num == RIGHT_KEY2)
		right_move(mp);
	if (key_num == DOWN_KEY || key_num == DOWN_KEY2)
		down_move(mp);
	if (key_num == LEFT_KEY || key_num == LEFT_KEY2)
		left_move(mp);
	if (nmoves != mp->moves_display)
	{
		ft_putnbr_fd(mp->moves_display, 0);
		write(2, "\n", 1);
	}
	convert_img_to_window(mp);
	return (EXIT_SUCCESS);
}
