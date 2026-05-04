/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:27:46 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:09:49 by okahrama        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_ps_node **list_a, t_ps_node **list_b,
		t_count *counter)
{
	int			i;
	int			j;
	int			index;
	t_medium	setup;

	medium_setup(&setup, *list_a);
	i = 0;
	j = 0;
	while (setup.full_size > i)
	{
		index = (*list_a)->index;
		if (index >= setup.chunk_min && index < setup.chunk_max)
		{
			patob(list_b, list_a, counter);
			if (index < setup.chunk_mid)
				rb(list_b, counter);
			i++;
			j++;
		}
		else
			ra(list_a, counter);
		if (setup.chunk_size == j)
			chunk_update(&setup, &j);
	}
	chunk_bstack_side(list_a, list_b, counter);
}

void	chunk_update(t_medium *setup, int *j)
{
	setup->chunk_min = setup->chunk_min + setup->chunk_size;
	setup->chunk_max = setup->chunk_max + setup->chunk_size;
	if (setup->chunk_max >= setup->full_size)
		setup->chunk_max = setup->full_size;
	setup->chunk_mid = (setup->chunk_min + setup->chunk_max) / 2;
	*j = 0;
}

void	medium_setup(t_medium *setup, t_ps_node *list_a)
{
	index_creater(list_a);
	setup->chunk_size = ft_lstsize(list_a);
	setup->full_size = setup->chunk_size;
	if (setup->chunk_size <= 100)
		setup->chunk_count = 5;
	else if (setup->chunk_size <= 500)
		setup->chunk_count = 11;
	else
		setup->chunk_count = setup->chunk_size / 25;
	setup->chunk_size = setup->chunk_size / setup->chunk_count;
	setup->chunk_max = setup->chunk_size;
	setup->chunk_min = 0;
	setup->chunk_mid = (setup->chunk_min + setup->chunk_max) / 2;
}

void	chunk_bstack_side(t_ps_node **list_a, t_ps_node **list_b,
		t_count *counter)
{
	int	max_pos;
	int	size;
	int	moves;

	while (*list_b)
	{
		max_index_founder(*list_b, &max_pos);
		size = ft_lstsize(*list_b);
		if (max_pos <= size / 2)
			moves = max_pos;
		else
			moves = size - max_pos;
		while (moves--)
		{
			if (max_pos <= size / 2)
				rb(list_b, counter);
			else
				rrb(list_b, counter);
		}
		pbtoa(list_a, list_b, counter);
	}
}
