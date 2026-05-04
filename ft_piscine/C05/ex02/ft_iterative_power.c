/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:05:27 by okahrama          #+#    #+#             */
/*   Updated: 2025/10/13 08:37:36 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	value;

	value = nb;
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power >= 1)
	{
		while (power > 1)
		{
			value *= nb;
			power--;
		}
	}
	return (value);
}
