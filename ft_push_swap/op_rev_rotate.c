/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:27:52 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:12:01 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps_node **list_a, t_count *counter)
{
	ps_rra(list_a);
	write(1, "rra\n", 4);
	counter->rra++;
	counter->total++;
}

void	rrb(t_ps_node **list_b, t_count *counter)
{
	ps_rrb(list_b);
	write(1, "rrb\n", 4);
	counter->rrb++;
	counter->total++;
}

void	rrr(t_ps_node **list_b, t_ps_node **list_a, t_count *counter)
{
	ps_rra(list_a);
	ps_rrb(list_b);
	write(1, "rrr\n", 4);
	counter->rrr++;
	counter->total++;
}
