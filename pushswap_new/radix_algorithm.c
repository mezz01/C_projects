/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:09:42 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/29 09:08:53 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort_help(t_node *first_num, int index, t_node **a)
{
	if (first_num->next_link->n_index == index)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

int	node_size(t_node *list)
{
	long	count;
	t_node	*list_tmp;

	count = 0;
	list_tmp = list;
	while (list_tmp)
	{
		list_tmp = list_tmp->next_link;
		count++;
	}
	return (count);
}

int	list_min_index(t_node **list, int min_num)
{
	t_node	*first_num;
	int		index;

	first_num = *list;
	index = first_num->n_index;
	while (first_num->next_link != NULL)
	{
		first_num = first_num->next_link;
		if ((first_num->n_index < index) && first_num->n_index != min_num)
		{
			index = first_num->n_index;
		}
	}
	return (index);
}

int	whats_max_bits(t_node **a)
{
	t_node	*first_num;
	int		biggest_num;
	int		count;

	first_num = *a;
	biggest_num = first_num->n_index;
	count = 0;
	while (first_num)
	{
		if (first_num->n_index > biggest_num)
			biggest_num = first_num->n_index;
		first_num = first_num->next_link;
	}
	while ((biggest_num >> count) != 0)
		count++;
	return (count);
}

void	apply_radix(t_node **a, t_node **b)
{
	t_node	*first_num;
	int		i;
	int		j;
	int		nd_size;
	int		max_bits;

	i = 0;
	first_num = *a;
	nd_size = node_size(first_num);
	max_bits = whats_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < nd_size)
		{
			first_num = *a;
			if (((first_num->n_index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (node_size(*b) != 0)
			pa(a, b);
		i++;
	}
}
