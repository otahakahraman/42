/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:02:13 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/23 15:51:00 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(void *addr)
{
	int				count;
	unsigned long	new_addr;

	count = 0;
	if (addr == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	new_addr = (unsigned long)addr;
	count += ft_putstr("0x");
	count += ft_puthex(new_addr);
	return (count);
}
