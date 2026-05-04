/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:27:55 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:09:49 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps_node **list_a, t_count *counter)
{
	ps_ra(list_a);
	write(1, "ra\n", 3);
	counter->ra++;
	counter->total++;
}

void	rb(t_ps_node **list_b, t_count *counter)
{
	ps_rb(list_b);
	write(1, "rb\n", 3);
	counter->rb++;
	counter->total++;
}

void	rr(t_ps_node **list_b, t_ps_node **list_a, t_count *counter)
{
	ps_ra(list_a);
	ps_rb(list_b);
	write(1, "rr\n", 3);
	counter->rr++;
	counter->total++;
}
