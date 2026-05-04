/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:01:36 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/23 15:49:43 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long hex_value)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (hex_value >= 16)
		count += ft_puthex(hex_value / 16);
	count += ft_putchar(base[hex_value % 16]);
	return (count);
}
