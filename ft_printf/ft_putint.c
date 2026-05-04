/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:02:29 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/23 15:50:50 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int c)
{
	int	count;

	count = 0;
	if (c == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (c < 0)
	{
		count += write(1, "-", 1);
		c = -c;
	}
	if (c >= 10)
	{
		count += ft_putint(c / 10);
	}
	count += ft_putchar(c % 10 + '0');
	return (count);
}
