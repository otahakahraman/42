/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:27:46 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:09:49 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_ps_node **list)
{
	t_ps_node	*first;
	t_ps_node	*second;

	if (!list || !(*list)->next || !(*list))
		return ;
	first = *list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list = second;
}

void	ps_sb(t_ps_node **list)
{
	t_ps_node	*first;
	t_ps_node	*second;

	if (!list || !(*list)->next || !(*list))
		return ;
	first = *list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list = second;
}

void	ps_ss(t_ps_node **list_a, t_ps_node **list_b)
{
	t_ps_node	*first;
	t_ps_node	*second;

	if (!list_a || !*list_a || !list_b || !*list_b)
		return ;
	if (!(*list_a)->next && !(*list_b)->next)
		return ;
	first = *list_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list_a = second;
	first = *list_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list_b = second;
}

t_ps_node	*take_first(t_ps_node **list)
{
	t_ps_node	*first;

	first = *list;
	*list = (*list)->next;
	return (first);
}
