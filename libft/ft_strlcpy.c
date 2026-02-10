/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:40:31 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/05 16:18:52 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	b;
	size_t	src_len;

	b = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[b] != '\0' && b < size - 1)
	{
		dst[b] = src[b];
		b++;
	}
	dst[b] = '\0';
	return (src_len);
}
