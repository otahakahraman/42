/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:35:54 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:11:03 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_ps_node **list_a, t_ps_node **list_b, t_count *counter)
{
	int	size;
	int	i;
	int	bit_count;
	int	bit;

	index_creater(*list_a);
	bit_count = get_bit_count(&size, *list_a);
	bit = 0;
	while (bit_count > bit)
	{
		i = 0;
		while (size > i)
		{
			if ((((*list_a)->index >> bit) & 1) == 0)
				patob(list_b, list_a, counter);
			else
				ra(list_a, counter);
			i++;
		}
		while (*list_b)
			pbtoa(list_a, list_b, counter);
		bit++;
	}
}

int	get_bit_count(int *size, t_ps_node *list_a)
{
	int	i;
	int	max_index;

	i = 0;
	max_index = max_index_founder_radix(list_a);
	*size = ft_lstsize(list_a);
	while (max_index > 0)
	{
		max_index = max_index / 2;
		i++;
	}
	return (i);
}

int	max_index_founder_radix(t_ps_node *list_a)
{
	int			max_index;
	int			index;
	t_ps_node	*temp;

	temp = list_a;
	max_index = -1;
	while (temp)
	{
		index = temp->index;
		if (index > max_index)
		{
			max_index = index;
		}
		temp = temp->next;
	}
	return (max_index);
}
