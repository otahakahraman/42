/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:44:59 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/23 15:03:11 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int c)
{
	int	count;

	count = 0;
	if (c >= 10)
	{
		count += ft_putuint(c / 10);
	}
	count += ft_putchar(c % 10 + '0');
	return (count);
}
