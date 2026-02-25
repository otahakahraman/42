/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:07:58 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/24 13:09:12 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	int				a;
	unsigned char	ch;

	a = 0;
	ch = (unsigned char)c;
	while (str[a] != '\0')
	{
		if (str[a] == ch)
			return ((char *)&str[a]);
		a++;
	}
	if (ch == '\0')
		return ((char *)str + a);
	return (NULL);
}
