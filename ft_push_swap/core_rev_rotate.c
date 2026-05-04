/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:27:34 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:09:49 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_ps_node **list_a)
{
	t_ps_node	*last;
	t_ps_node	*prev;

	last = *list_a;
	prev = NULL;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *list_a;
	*list_a = last;
}

void	ps_rrb(t_ps_node **list_b)
{
	t_ps_node	*last;
	t_ps_node	*prev;

	last = *list_b;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *list_b;
	*list_b = last;
}

void	ps_rrr(t_ps_node **list_a, t_ps_node **list_b)
{
	if (list_a && *list_a && (*list_a)->next)
		ps_rra(list_a);
	if (list_b && *list_b && (*list_b)->next)
		ps_rrb(list_b);
}
