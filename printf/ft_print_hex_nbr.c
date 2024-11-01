/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:06:06 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/30 15:11:25 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_nbr(unsigned int n, int upper, int initlen)
{
	char		*hex;
	static int	len = 0;

	len = initlen;
	if (upper == 1)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
	{
		if (ft_print_hex_nbr(n / 16, upper, len) == -1)
			return (-1);
	}
	if (ft_putchar_fd_printf(hex[n % 16], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}
