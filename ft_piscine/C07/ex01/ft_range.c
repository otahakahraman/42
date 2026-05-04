/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:04:51 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/10 17:16:07 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	*ft_range(int min, int max)
{
	int	*dup;
	int	size;
	int	i;
	int	b;

	i = 0;
	size = max - min;
	dup = (int *)malloc(sizeof(int)* size);
	if (min >= max)
		return (0);
	if (!dup)
		return (0);
	while (min < max)
	{
		dup[i] = min;
		i++;
		min++;
	}
	dup[i] = '\0';
	return (dup);
}
