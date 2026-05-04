/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:44:52 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/26 16:32:59 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_ps_node	*list_a;
	t_ps_node	*list_b;
	t_count		counter;

	list_b = NULL;
	list_a = NULL;
	list_a = parse_control(argc, argv, &counter);
	init_counter(&counter);
	if (list_a == NULL)
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (is_sorted(list_a) == 1)
	{
		free_list(list_a);
		return ;
	}
	disorder(list_a, &counter);
	pick_algorithm(&list_a, &list_b, &counter);
	if ((ft_strcmp(argv[1], "--bench") == 0) || (argv[2] != NULL
			&& ft_strcmp(argv[2], "--bench") == 0))
		print_bench(&counter);
	free_list(list_a);
	free_list(list_b);
}

void	init_counter(t_count *counter)
{
	counter->sa = 0;
	counter->sb = 0;
	counter->ss = 0;
	counter->pa = 0;
	counter->pb = 0;
	counter->ra = 0;
	counter->rb = 0;
	counter->rr = 0;
	counter->rra = 0;
	counter->rrb = 0;
	counter->rrr = 0;
	counter->total = 0;
	counter->strategy = 0;
	counter->disorder = 0.0;
}

void	pick_algorithm(t_ps_node **list_a, t_ps_node **list_b, t_count *counter)
{
	if (counter->alg_numb == 1)
	{
		selection_sort(list_a, list_b, counter);
		counter->strategy = 1;
	}
	else if (counter->alg_numb == 2)
	{
		chunk_sort(list_a, list_b, counter);
		counter->strategy = 2;
	}
	else if (counter->alg_numb == 3)
	{
		radix_sort(list_a, list_b, counter);
		counter->strategy = 3;
	}
	else if (counter->alg_numb == 4)
	{
		adaptive(list_a, list_b, counter);
		counter->strategy = 4;
	}
	else
	{
		adaptive(list_a, list_b, counter);
		counter->strategy = 4;
	}
}

void	adaptive(t_ps_node **list_a, t_ps_node **list_b, t_count *counter)
{
	disorder(*list_a, counter);
	if (counter->disorder < 0.2 || counter->numb_size <= 5)
	{
		selection_sort(list_a, list_b, counter);
		counter->adaptive_strategy = 1;
	}
	else if (counter->disorder >= 0.2 && counter->disorder < 0.5)
	{
		chunk_sort(list_a, list_b, counter);
		counter->adaptive_strategy = 2;
	}
	else
	{
		radix_sort(list_a, list_b, counter);
		counter->adaptive_strategy = 3;
	}
}

int	is_sorted(t_ps_node *list)
{
	while (list && list->next)
	{
		if (list->content < list->next->content)
			list = list->next;
		else
			return (0);
	}
	return (1);
}
