/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 04:39:12 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/16 03:24:38 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	messg1(void)
{
	write(2, "ERROR\nBig map size\n", 20);
	exit(EXIT_FAILURE);
}

void	messg2(void)
{
	write(2, "ERROR\nProblem with xpm file\n", 29);
	exit(EXIT_FAILURE);
}
