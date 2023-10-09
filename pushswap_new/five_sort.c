/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:40:44 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/29 10:50:16 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_nums_sort(t_node **a)
{
	t_node	*first_num;
	int		index;
	int		next_index;

	first_num = *a;
	index = list_min_index(a, -1);
	next_index = list_min_index(a, index);
	if (check_if_sorted(a))
		return ;
	if (first_num->n_index == index
		&& first_num->next_link->n_index != next_index)
	{
		rra(a);
		sa(a);
	}
	else if (first_num->n_index == next_index)
	{
		if (first_num->next_link->n_index == index)
			sa(a);
		else
			rra(a);
	}
	else
		three_sort_help(first_num, index, a);
}

void	double_ra(t_node **a)
{
	ra(a);
	ra(a);
}

void	double_rra(t_node **a)
{
	rra(a);
	rra(a);
}

void	four_nums_sort(t_node **a, t_node **b)
{
	int	next_index;
	int	smallest_index;

	smallest_index = list_min_index(a, -1);
	next_index = how_far(*a, smallest_index);
	if (check_if_sorted(a))
		return ;
	if (next_index == 1)
		ra(a);
	else if (next_index == 2)
		double_ra(a);
	else if (next_index == 3)
		rra(a);
	if (check_if_sorted(a))
		return ;
	pb(a, b);
	three_nums_sort(a);
	pa(a, b);
}

void	five_nums_sort(t_node **a, t_node **b)
{
	int	next_index;
	int	smallest_index;

	smallest_index = list_min_index(a, -1);
	next_index = how_far(*a, smallest_index);
	if (check_if_sorted(a))
		return ;
	if (next_index == 1)
		ra(a);
	else if (next_index == 2)
		double_ra(a);
	else if (next_index == 3)
		double_rra(a);
	else if (next_index == 4)
		rra(a);
	if (check_if_sorted(a))
		return ;
	pb(a, b);
	four_nums_sort(a, b);
	pa(a, b);
}
