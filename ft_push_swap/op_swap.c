/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:27:58 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:09:49 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps_node **list, t_count *counter)
{
	ps_sa(list);
	write(1, "sa\n", 3);
	counter->sa++;
	counter->total++;
}

void	sb(t_ps_node **list, t_count *counter)
{
	ps_sb(list);
	write(1, "sb\n", 3);
	counter->sb++;
	counter->total++;
}

void	ss(t_ps_node **list_a, t_ps_node **list_b, t_count *counter)
{
	ps_sa(list_a);
	ps_sb(list_b);
	write(1, "ss\n", 3);
	counter->ss++;
	counter->total++;
}
