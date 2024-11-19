/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:53:19 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/19 11:46:33 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

#define BUFFER_SIZE 1024

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int		bit_count = 0;
	static char		character = 0;
	pid_t			client_pid;

	(void)context;
	client_pid = info->si_pid;
	character <<= 1;
	if (sig == SIGUSR1)
		character |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (character == '\0')
		{
			write(1, "\n", 1);
		}
		else
		{
			write(1, &character, 1);
		}
		character = 0;
		bit_count = 0;
		kill(client_pid, SIGUSR1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
