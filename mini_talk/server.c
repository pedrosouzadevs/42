/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:42:48 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/15 17:02:00 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signo, siginfo_t *info, void *context)
{
	static char		c;
	static int		bit;
	static pid_t	client_pid;

	(void)context;
	if (info->si_pid)
		client_pid = info->si_pid;
	if (signo == SIGUSR1)
		c |= (0x80 >> bit++);
	else if (signo == SIGUSR2)
		c &= ~(0x80 >> bit++);
	if (CHAR_BIT == bit)
	{
		bit = 0;
		if (c == '\0')
		{
			write(STDOUT_FILENO, "\n", 1);
			kill(client_pid, SIGUSR2);
			c = 0;
			return ;
		}
		write(STDOUT_FILENO, &c, 1);
		c = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		ft_printf("Usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	ft_printf("Server PID: %d\n", getpid());
	signal_made(SIGUSR1, handler, true);
	signal_made(SIGUSR2, handler, true);
	while (1337)
		pause();
	return (EXIT_SUCCESS);
}
