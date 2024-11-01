/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:53:19 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/01 11:58:29 by dalbano          ###   ########.fr       */
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
		buffer[g_index++] = '1'; // Arbitrarily assign '1' for SIGUSR1
	}
	else if (sig == SIGUSR2)
	{
		buffer[g_index++] = '0'; // Arbitrarily assign '0' for SIGUSR2
	}
	// When receiving the end of string signal (e.g., a specific signal), print the buffer
	if (g_index > 0 && (sig == SIGUSR2))
	{
		// Using SIGUSR2 as an indication of end of message
		buffer[g_index] = '\0'; // Null-terminate the string
		printf("Received: %s\n", buffer);
		// Reset for next message
		g_index = 0;
	}
}

int main()
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	printf("Server PID: %d\n", pid);
	// Set up signal handlers
	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	// Keep the server running
	while (1)
		pause(); // Wait for signals
	return (0);
}
