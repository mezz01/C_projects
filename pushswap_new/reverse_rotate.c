/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:21:34 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/28 09:55:09 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_node **a)
{
	int	ret;

	ret = down_rotating_nums(a);
	if (ret == false)
		return (false);
	ft_putstr_fd("rra", 1);
	return (true);
}

int	rrb(t_node **b)
{
	int	ret;

	ret = down_rotating_nums(b);
	if (ret == false)
		return (false);
	ft_putstr_fd("rrb", 1);
	return (true);
}

int	rrr(t_node **a, t_node **b)
{
	if ((node_size(*a) < 2) || (node_size(*b) < 2))
		return (false);
	down_rotating_nums(a);
	down_rotating_nums(b);
	ft_putstr_fd("rrr", 1);
	return (true);
}
