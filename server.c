/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:53:19 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/01 11:43:25 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Process ID: %d\n", pid);
	return (0);
}
