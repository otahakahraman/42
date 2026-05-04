/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:21:25 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/05 16:17:35 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	else
	{
		while (s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0' && a < n - 1)
		{
			a++;
		}
	}
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
