/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:08:05 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/01/17 08:55:01 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <stdbool.h>
# include "printf/ft_printf.h"

enum e_ack
{
	BUSY,
	READY
};

void	kill_made(pid_t pid, int signo);
void	signal_made(int signo, void *handler, bool use_siginfo);

#endif
