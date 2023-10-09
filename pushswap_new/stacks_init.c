/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:25:39 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/26 20:38:28 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_node **str)
{
	t_node	*tmp_str;

	while (*str)
	{
		tmp_str = *str;
		*str = (*str)->next_link;
		free(tmp_str);
	}
}

// return a pointer to the last number in the node :
t_node	*last_item(t_node *first_num)
{
	t_node	*ret;

	ret = first_num;
	while (ret->next_link != NULL)
		ret = ret->next_link;
	return (ret);
}

// Stack init :
// Creating a new node and return a pointer to it :
t_node	*new_node(int number)
{
	t_node	*first_num;

	first_num = (t_node *)malloc(sizeof(*first_num));
	if (!first_num)
		return (NULL);
	first_num->number = number;
	first_num->n_index = -1;
	first_num->next_link = NULL;
	return (first_num);
}

// adding the node the end of the stack :
// if there is no node in the stack we inisialise that node as the first one

void	add_node_to_stack(t_node **a, t_node *first_num)
{
	t_node	*last_num;
	t_node	*pre_last_num;

	last_num = *a;
	if (last_num)
	{
		pre_last_num = last_item(last_num);
		pre_last_num->next_link = first_num;
		first_num->next_link = NULL;
	}
	else
	{
		(*a) = first_num;
		(*a)->next_link = NULL;
	}
}
