/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:09:14 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/30 15:11:25 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_putnbr_unsigned_fd_printf(unsigned long n, int fd)
{
	if (n >= 10)
	{
		if (ft_putnbr_unsigned_fd_printf(n / 10, fd) == -1)
			return (-1);
	}
	if (ft_putchar_fd_printf(n % 10 + '0', fd) == -1)
		return (-1);
	return (0);
}

int	ft_print_unsigned_nbr(unsigned long n)
{
	if (ft_putnbr_unsigned_fd_printf(n, 1) == -1)
		return (-1);
	return (get_len(n));
}
