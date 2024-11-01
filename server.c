/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:53:19 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/01 13:27:18 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <signal.h>

#define BUFFER_SIZE 1024

char	g_buffer[BUFFER_SIZE];
int		g_index = 0;

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
	{
		g_buffer[g_index++] = '1';
	}
	else if (sig == SIGUSR2)
	{
		g_buffer[g_index++] = '0';
	}
	if (g_index > 0 && (sig == SIGUSR2))
	{
		g_buffer[g_index] = '\0';
		ft_printf("Received: %s\n", g_buffer);
		g_index = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
