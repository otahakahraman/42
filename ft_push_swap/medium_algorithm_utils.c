/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 20:33:49 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:10:51 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_index_founder(t_ps_node *list_b, int *max_pos)
{
	int			max_index;
	int			index;
	int			pos;
	t_ps_node	*temp;

	temp = list_b;
	pos = 0;
	max_index = -1;
	while (temp)
	{
		index = temp->index;
		if (index > max_index)
		{
			max_index = index;
			*max_pos = pos;
		}
		temp = temp->next;
		pos++;
	}
}

void	index_creater(t_ps_node *list_a)
{
	t_ps_node	*temp;
	t_ps_node	*temp3;
	int			value;
	int			i;

	temp = list_a;
	temp3 = list_a;
	while (temp)
	{
		i = 0;
		value = temp->content;
		while (list_a)
		{
			if (value > list_a->content)
				i++;
			list_a = list_a->next;
		}
		temp->index = i;
		list_a = temp3;
		temp = temp->next;
	}
}

int	first_index(t_ps_node *list_a, int value)
{
	int	i;

	i = 0;
	while (list_a)
	{
		if (value > list_a->content)
			i++;
		list_a = list_a->next;
	}
	return (i);
}
