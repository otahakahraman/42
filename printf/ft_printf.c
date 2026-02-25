/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:18:01 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/24 13:28:54 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 'd')
		return (ft_putint(va_arg(*args, int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(*args, unsigned int)));
	else if (c == 'X')
		return (ft_puthexx(va_arg(*args, unsigned int)));
	else if (c == 'p')
		return (ft_putaddr(va_arg(*args, void *)));
	else if (c == 'i')
		return (ft_putint(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putuint(va_arg(*args, unsigned int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	count = 0;
	i = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!ft_strchr("cspdiuxX%", format[i]) || format[i] == '\0')
				return (-1);
			if (format[i])
				count += ft_control(format[i], &args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
