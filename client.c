/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:30:25 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/03 12:47:23 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <signal.h>
// #include <stdio.h>

volatile sig_atomic_t	g_see_res = 0;

void	see_res(int sig)
{
	(void)sig;
	g_see_res = 1;
}

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

void	process_while(char *message, pid_t server_pid, size_t i)
{
	g_see_res = 0;
	send_character(message[i], server_pid);
	while (!g_see_res)
		pause();
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	char				*message;
	size_t				i;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(1, "Usage: ./client <server_pid> <string>\n", 38);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	sa.sa_handler = see_res;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	i = -1;
	while (++i < ft_strlen(message))
		process_while(message, server_pid, i);
	g_see_res = 0;
	send_character('\0', server_pid);
	while (!g_see_res)
		pause();
	return (0);
}
