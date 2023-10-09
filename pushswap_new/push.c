/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:19:13 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/27 03:24:54 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_node **a, t_node **b)
{
	int	ret;

	ret = push_top_nums(b, a);
	if (ret == false)
		return (false);
	ft_putstr_fd("pa", 1);
	return (true);
}

int	pb(t_node **a, t_node **b)
{
	int	ret;

	ret = push_top_nums(a, b);
	if (ret == false)
		return (false);
	ft_putstr_fd("pb", 1);
	return (true);
}
