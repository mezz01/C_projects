/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:18:45 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/27 03:20:43 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_node **a)
{
	if (swap_top_nums(a) == false)
		return (false);
	ft_putstr_fd("sa", 1);
	return (true);
}

int	sb(t_node **b)
{
	if (swap_top_nums(b) == false)
		return (false);
	ft_putstr_fd("sb", 1);
	return (true);
}

int	ss(t_node **a, t_node **b)
{
	if ((node_size(*a) < 2) || (node_size(*b) < 2))
		return (false);
	swap_top_nums(a);
	swap_top_nums(b);
	ft_putstr_fd("ss", 1);
	return (true);
}
