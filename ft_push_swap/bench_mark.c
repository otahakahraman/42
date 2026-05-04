/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mark.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:53:19 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 19:59:06 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(t_count *counter)
{
	disorder_part(counter);
	strategy_part(counter);
	total_ops_part(counter);
	ops_part(counter);
}

void	disorder_part(t_count *counter)
{
	int		int_part;
	int		decimal_part;
	float	decimal;
	float	disorder;

	disorder = counter->disorder * 100;
	int_part = (int)disorder;
	decimal = disorder - int_part;
	decimal_part = (int)(decimal * 100);
	ft_putstr_fd("[bench] disorder: ");
	ft_putnbr_fd(int_part);
	write(2, ".", 1);
	if (decimal_part < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal_part);
	write(2, "%\n", 2);
}

void	strategy_part(t_count *counter)
{
	if (counter->strategy == 1)
		ft_putstr_fd("[bench] strategy: Simple / O(n^2)\n");
	else if (counter->strategy == 2)
		ft_putstr_fd("[bench] strategy: Medium / O(n√n)\n");
	else if (counter->strategy == 3)
		ft_putstr_fd("[bench] strategy: Complex / O(n log n)\n");
	else if (counter->strategy == 4)
	{
		ft_putstr_fd("[bench] strategy: Adaptive / ");
		if (counter->adaptive_strategy == 1)
			ft_putstr_fd("O(n^2)\n");
		else if (counter->adaptive_strategy == 2)
			ft_putstr_fd("O(n√n)\n");
		else if (counter->adaptive_strategy == 3)
			ft_putstr_fd("O(n log n)\n");
	}
}

void	total_ops_part(t_count *counter)
{
	ft_putstr_fd("[bench] total_ops: ");
	ft_putnbr_fd(counter->total);
	write(2, "\n", 2);
}

void	ops_part(t_count *counter)
{
	ft_putstr_fd("[bench] sa: ");
	ft_putnbr_fd(counter->sa);
	ft_putstr_fd(" sb: ");
	ft_putnbr_fd(counter->sb);
	ft_putstr_fd(" ss: ");
	ft_putnbr_fd(counter->ss);
	ft_putstr_fd(" pa: ");
	ft_putnbr_fd(counter->pa);
	ft_putstr_fd(" pb: ");
	ft_putnbr_fd(counter->pb);
	write(2, "\n", 2);
	ft_putstr_fd("[bench] ra: ");
	ft_putnbr_fd(counter->ra);
	ft_putstr_fd(" rb: ");
	ft_putnbr_fd(counter->rb);
	ft_putstr_fd(" rr: ");
	ft_putnbr_fd(counter->rr);
	ft_putstr_fd(" rra: ");
	ft_putnbr_fd(counter->rra);
	ft_putstr_fd(" rrb: ");
	ft_putnbr_fd(counter->rrb);
	ft_putstr_fd(" rrr: ");
	ft_putnbr_fd(counter->rrr);
	write(2, "\n", 2);
}
