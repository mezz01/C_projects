/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:54:30 by mmezzat           #+#    #+#             */
/*   Updated: 2023/06/13 00:28:01 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sending_signal(int server_id, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
		usleep(WAIT);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	server_id;
	int	i;

	i = 0;
	if (ac == 3 && av[1][0] != '-')
	{
		server_id = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			sending_signal(server_id, av[2][i]);
			i++;
		}
		sending_signal(server_id, '\0');
	}
	else
	{
		write(2, "Error please reenter pid and string to send", 44);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
