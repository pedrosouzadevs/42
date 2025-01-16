/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:07:43 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/15 16:41:43 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_server_ack;

static void	ack_handler(void)
{
	g_server_ack = READY;
}

static void	end_handler(void)
{
	write(STDOUT_FILENO, "\t✅ Message received ✅\n", 27);
	exit(EXIT_SUCCESS);
}

static void	send_char(char c, pid_t pid)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			kill_made(pid, SIGUSR1);
		else
			kill_made(pid, SIGUSR2);
		bit++;
		while (BUSY == g_server_ack)
			usleep(42);
		g_server_ack = BUSY;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	int 	i;

	g_server_ack = BUSY;
	i = 0;
	if (argc != 3)
	{
		ft_printf("Usage: %s [PID] [MESSAGE]\n", argv[0]);
		return (EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	message = argv[2];
	signal_made(SIGUSR1, ack_handler, false);
	signal_made(SIGUSR2, end_handler, false);
	while (message[i])
		send_char(message[i++], pid);
	send_char('\0', pid);
	return (EXIT_SUCCESS);
}
