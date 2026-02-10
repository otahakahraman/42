/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:15:27 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/10 17:16:16 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int ft_ultimate_range(int **range, int min, int max)

{

	int	size;
	int	i;

	i = 0;
	size = max - min;
	*range = (int *)malloc(sizeof(int)*size);
	if (!*range)
		return (-1);
	

	if (min >= max)
		return (0);
	
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	
	return (size);
}
