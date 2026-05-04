/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:27:46 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:09:49 by okahrama        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	disorder(t_ps_node *list_a, t_count *counter)
{
	float		res;
	float		count;
	int			i;
	t_ps_node	*temp;

	count = 0;
	i = 0;
	while (list_a)
	{
		temp = list_a->next;
		while (temp)
		{
			if (list_a->content > temp->content)
				count++;
			temp = temp->next;
		}
		i++;
		list_a = list_a->next;
	}
	res = (i * (i - 1)) / 2.0;
	counter->disorder = count / res;
}
