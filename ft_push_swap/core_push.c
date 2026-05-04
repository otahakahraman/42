/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:27:27 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:09:49 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_patob(t_ps_node **list_b, t_ps_node **list_a)
{
	t_ps_node	*first;

	first = take_first(list_a);
	ft_lstadd_front(list_b, first);
}

void	ps_pbtoa(t_ps_node **list_a, t_ps_node **list_b)
{
	t_ps_node	*first;

	first = take_first(list_b);
	ft_lstadd_front(list_a, first);
}
