/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:41:19 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/26 16:43:23 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_digits(char *nptr, int i, int sign)
{
	long long	num;

	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + (nptr[i] - '0');
		if ((sign == 1 && num > 2147483647) || (sign == -1 && num > 2147483648))
			return (0);
		i++;
	}
	if (nptr[i] != '\0')
		return (0);
	return (1);
}

int	handle_single(char *arg, t_ps_node **list)
{
	if (control(arg) == 0)
		return (0);
	ft_lstadd_back(list, new_node(ft_atoi(arg)));
	return (1);
}

int	handle_split(char *arg, t_ps_node **list)
{
	char	**split;
	int		j;

	j = 0;
	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	while (split[j])
	{
		if (control(split[j]) == 0)
		{
			free_split(split);
			return (0);
		}
		ft_lstadd_back(list, new_node(ft_atoi(split[j])));
		j++;
	}
	free_split(split);
	return (1);
}
