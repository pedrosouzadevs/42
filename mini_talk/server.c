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

int main(int argc, char **argv)
{
	printf("Server PID: %d\n", getpid());
	while (1337)
		pause();
	return (EXIT_SUCCESS);
}
