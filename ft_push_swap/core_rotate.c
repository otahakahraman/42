/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:27:43 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:09:49 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_ps_node **list_a)
{
	t_ps_node	*first;
	t_ps_node	*last;

	if (!list_a || !*list_a || !(*list_a)->next)
		return ;
	first = *list_a;
	last = *list_a;
	while (last->next)
		last = last->next;
	*list_a = first->next;
	first->next = NULL;
	last->next = first;
}

void	ps_rb(t_ps_node **list_b)
{
	t_ps_node	*first;
	t_ps_node	*last;

	if (!list_b || !*list_b || !(*list_b)->next)
		return ;
	first = *list_b;
	last = *list_b;
	while (last->next)
		last = last->next;
	*list_b = first->next;
	first->next = NULL;
	last->next = first;
}

void	ps_rr(t_ps_node **list_a, t_ps_node **list_b)
{
	t_ps_node	*first;

	if (!list_a || !*list_a || !list_b || !*list_b)
		return ;
	if ((*list_a)->next)
	{
		first = take_first(list_a);
		ft_lstadd_back(list_a, first);
	}
	if ((*list_b)->next)
	{
		first = take_first(list_b);
		ft_lstadd_back(list_b, first);
	}
}
