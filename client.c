/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:30:25 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/03 11:42:01 by dalbano          ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	size_t	i;

	if (argc != 3)
	{
		write(1, "Usage: ./client <server_pid> <string>\n", 38);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (i < ft_strlen(message))
	{
		send_character(message[i], server_pid);
		i++;
	}
	send_character('\0', server_pid);
	return (0);
}
