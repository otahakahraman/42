/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:02:40 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/05 16:55:17 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				b;
	unsigned char	uc;

	uc = (unsigned char)c;
	b = ft_strlen(str);
	while (b >= 0)
	{
		if ((unsigned char)str[b] == uc)
			return ((char *)str + b);
		b--;
	}
	return (NULL);
}
