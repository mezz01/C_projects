/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:20:49 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/27 03:21:20 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_node **a)
{
	int	ret;

	ret = rotating_nums(a);
	if (ret == false)
		return (false);
	ft_putstr_fd("ra", 1);
	return (true);
}

int	rb(t_node **b)
{
	int	ret;

	ret = rotating_nums(b);
	if (ret == false)
		return (false);
	ft_putstr_fd("rb", 1);
	return (true);
}

int	rr(t_node **a, t_node **b)
{
	if ((node_size(*a)) < 2 || (node_size(*b)) < 2)
		return (false);
	rotating_nums(a);
	rotating_nums(b);
	ft_putstr_fd("rr", 1);
	return (true);
}
