/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:52:14 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/27 02:32:09 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_next_min(t_node **stack)
{
	t_node	*head;
	t_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->n_index == -1) && (!has_min
					|| head->number < min->number))
			{
				min = head;
				has_min = 1;
			}
			head = head->next_link;
		}
	}
	return (min);
}

void	create_indexes(t_node **stack)
{
	t_node	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->n_index = index++;
		head = get_next_min(stack);
	}
}

int	check_if_sorted(t_node **list)
{
	t_node	*first_num;

	first_num = *list;
	while (first_num && first_num->next_link != NULL)
	{
		if (first_num->number > first_num->next_link->number)
			return (false);
		first_num = first_num->next_link;
	}
	return (true);
}

void	early_sort(t_node **a, t_node **b)
{
	t_node	*first_num;

	first_num = *a;
	if (node_size(*a) == 0 || node_size(*a) == 1 || check_if_sorted(a))
	{
		return ;
	}
	if (node_size(first_num) == 2)
		sa(a);
	else if (node_size(first_num) <= 5)
		limited_num_sort(a, b);
	else
	{
		apply_radix(a, b);
	}
}

int	how_far(t_node *a, int c_index)
{
	int	d;

	d = 0;
	while ((a))
	{
		if ((a)->n_index == c_index)
			break ;
		d++;
		a = a->next_link;
	}
	return (d);
}
