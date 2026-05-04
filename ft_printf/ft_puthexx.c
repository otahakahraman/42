/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:01:55 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/23 15:16:52 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexx(unsigned int hex_value)
{
	int		count;
	char	*base;

	base = "0123456789ABCDEF";
	count = 0;
	if (hex_value >= 16)
		count += ft_puthexx(hex_value / 16);
	count += ft_putchar(base[hex_value % 16]);
	return (count);
}
