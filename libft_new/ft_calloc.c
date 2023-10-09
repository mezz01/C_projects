/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:03:32 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/12 23:34:39 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t n_blocks, size_t size_block)
{
	void	*alloc_ptr;
	size_t	n;

	n = n_blocks * size_block;
	alloc_ptr = malloc(n);
	if (alloc_ptr == NULL)
		return (alloc_ptr);
	ft_bzero(alloc_ptr, n);
	return (alloc_ptr);
}
