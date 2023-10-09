/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 04:08:54 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/28 09:49:07 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(const char *str, int fd)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		write(fd, &str[i], 1);
	}
	write(fd, "\n", 1);
}

int	swap_top_nums(t_node **list)
{
	t_node	*first_num;
	t_node	*second_num;
	int		action_number;
	int		action_index;

	if (node_size(*list) < 2)
		return (false);
	first_num = *list;
	second_num = first_num->next_link;
	action_number = first_num->number;
	action_index = first_num->n_index;
	first_num->number = second_num->number;
	first_num->n_index = second_num->n_index;
	second_num->number = action_number;
	second_num->n_index = action_index;
	return (true);
}

int	push_top_nums(t_node **from_stack, t_node **go_to_stack)
{
	t_node	*tmp;
	t_node	*from_top;
	t_node	*to_go_top;

	if (node_size(*from_stack) == 0)
		return (false);
	to_go_top = *go_to_stack;
	from_top = *from_stack;
	tmp = from_top;
	from_top = from_top->next_link;
	*from_stack = from_top;
	if (!to_go_top)
	{
		to_go_top = tmp;
		to_go_top->next_link = NULL;
		*go_to_stack = to_go_top;
	}
	else
	{
		tmp->next_link = to_go_top;
		*go_to_stack = tmp;
	}
	return (true);
}
// Creating the rotate function and capturers :

int	rotating_nums(t_node **list)
{
	t_node	*first_num;
	t_node	*last_num;

	if (node_size(*list) < 2)
		return (false);
	first_num = *list;
	last_num = last_item(first_num);
	*list = first_num->next_link;
	first_num->next_link = NULL;
	last_num->next_link = first_num;
	return (true);
}
// Shift all elemnts like rotate but shift down so in reverse

int	down_rotating_nums(t_node **list)
{
	t_node	*first_num;
	t_node	*last_num;

	if (node_size(*list) < 2)
		return (false);
	first_num = *list;
	last_num = last_item(first_num);
	while (first_num)
	{
		if (first_num->next_link->next_link == NULL)
		{
			first_num->next_link = NULL;
			break ;
		}
		first_num = first_num->next_link;
	}
	last_num->next_link = *list;
	*list = last_num;
	return (true);
}
