/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:30:25 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/01 12:02:56 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <signal.h>

void	send_character(char c, pid_t server_pid)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if (c & (1 << i)) // Check each bit
			kill(server_pid, SIGUSR1); // Send SIGUSR1 for bit '1'
		else
			kill(server_pid, SIGUSR2); // Send SIGUSR2 for bit '0'
		usleep(100); // Delay to avoid sending too quickly
	}
	// Indicate end of message
	kill(server_pid, SIGUSR2); // Sending SIGUSR2 as a message terminator
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	size_t	temp;

	temp = -1;
	if (argc != 3)
	{
		ft_printf(stderr, "Usage: %s <server_pid> <string>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	*message = argv[2];
	while (++temp < ft_strlen(message))
		send_character(message[temp], server_pid);
	return (0);
}
