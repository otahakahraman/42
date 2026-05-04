/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:20:28 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:10:36 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_ps_node **list_a, t_ps_node **list_b, t_count *counter)
{
	int	min_index;

	while (*list_a)
	{
		min_index = find_min_index(*list_a);
		operations(list_a, list_b, min_index, counter);
	}
	while (*list_b)
	{
		pbtoa(list_a, list_b, counter);
	}
}

int	find_min_index(t_ps_node *list_a)
{
	t_ps_node	*temp;
	int			min_value;
	int			min_index;
	int			i;

	min_value = list_a->content;
	min_index = 0;
	temp = list_a;
	i = 0;
	while (temp->next)
	{
		if (min_value > temp->next->content)
		{
			min_value = temp->next->content;
			min_index = i + 1;
		}
		temp = temp->next;
		i++;
	}
	return (min_index);
}

void	operations(t_ps_node **list_a, t_ps_node **list_b, int min_index,
		t_count *counter)
{
	int	size;
	int	moves;

	size = ft_lstsize(*list_a);
	moves = size - min_index;
	if (min_index <= size / 2)
	{
		while (min_index--)
			ra(list_a, counter);
	}
	else
	{
		while (moves--)
			rra(list_a, counter);
	}
	patob(list_b, list_a, counter);
}
