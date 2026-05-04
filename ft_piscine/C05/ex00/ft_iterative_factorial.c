/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 09:28:53 by okahrama          #+#    #+#             */
/*   Updated: 2025/10/13 08:34:20 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	value;

	value = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else if (nb >= 1)
	{
		while (nb > 1)
		{
			value *= nb - 1;
			nb--;
		}
	}
	return (value);
}
