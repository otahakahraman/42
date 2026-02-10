/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:50:59 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/05 17:34:13 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenfind(long n)
{
	int	len;

	len = 1;
	if (n == 0)
	{
		return (len);
	}
	else if (n < 0)
	{
		n *= -1;
		len++;
	}
	if (n > 0)
	{
		while (n > 9)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*arr;
	long	len;
	long	num;
	int		i;

	num = n;
	len = lenfind(num);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	if (n == 0)
		arr[0] = '0';
	arr[len] = '\0';
	if (n < 0)
	{
		num = -num;
		arr[0] = '-';
	}
	i = len - 1;
	while (num > 0)
	{
		arr[i--] = num % 10 + '0';
		num = num / 10;
	}
	return (arr);
}
