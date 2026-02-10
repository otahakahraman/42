/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:24:22 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/05 16:18:01 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	a;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && len > i)
	{
		a = 0;
		while (big[i + a] == little[a] && big[i + a] != '\0' && i + a < len)
		{
			if (little[a + 1] == '\0')
				return ((char *)&big[i]);
			a++;
		}
		i++;
	}
	return (NULL);
}
