/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:30:25 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/01 13:26:09 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>

void	send_character(char c, pid_t server_pid)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
	}
	kill(server_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	size_t	temp;

	temp = -1;
	message = NULL;
	if (argc != 3)
	{
		write(1, "Usage: ./client <server_pid> <string>\n", 38);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	*message = *argv[2];
	while (++temp < ft_strlen(message))
		send_character(message[temp], server_pid);
	return (0);
}
