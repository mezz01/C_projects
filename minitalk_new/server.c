/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 05:56:29 by mmezzat           #+#    #+#             */
/*   Updated: 2023/06/13 00:32:28 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receiving_signal(int signal, siginfo_t *info, void *context)
{
	static int				bit;
	static unsigned char	print_chr;
	static int				client_id;
	static int				pid;

	pid = info->si_pid;
	if (pid != client_id)
	{
		client_id = pid;
		bit = 0;
		print_chr = 0;
		write(1, "\n", 1);
	}
	(void)context;
	if (signal == SIGUSR1)
		print_chr |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", print_chr);
		bit = 0;
		print_chr = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sigac;

	(void)av;
	if (ac != 1)
	{
		write(2, "please type : ./server !\n", 26);
		return (EXIT_FAILURE);
	}
	ft_printf("Your server pid is : %d\n", getpid());
	sigac.sa_sigaction = receiving_signal;
	sigemptyset(&sigac.sa_mask);
	sigac.sa_flags = 0;
	while (ac == 1)
	{
		sigaction(SIGUSR1, &sigac, NULL);
		sigaction(SIGUSR2, &sigac, NULL);
		pause();
	}
	return (EXIT_SUCCESS);
}
