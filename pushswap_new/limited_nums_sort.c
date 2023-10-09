/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limited_nums_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 05:08:10 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/29 10:08:18 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	limited_num_sort(t_node **a, t_node **b)
{
	if (node_size(*a) == 3)
		three_nums_sort(a);
	else if (node_size(*a) == 4)
		four_nums_sort(a, b);
	else if (node_size(*a) == 5)
		five_nums_sort(a, b);
}
