/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:27:50 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:09:49 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pbtoa(t_ps_node **list_a, t_ps_node **list_b,
		t_count *counter)
{
	ps_pbtoa(list_a, list_b);
	write(1, "pa\n", 3);
	counter->pa++;
	counter->total++;
}

void	patob(t_ps_node **list_b, t_ps_node **list_a,
		t_count *counter)
{
	ps_patob(list_b, list_a);
	write(1, "pb\n", 3);
	counter->pb++;
	counter->total++;
}
