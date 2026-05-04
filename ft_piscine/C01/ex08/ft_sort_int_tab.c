/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:15:16 by okahrama          #+#    #+#             */
/*   Updated: 2025/10/05 14:37:02 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	node;

	b = 1;
	while (b)
	{
		b = 0;
		a = 0;
		while (a < size - 1)
		{
			if (tab[a] > tab[a + 1])
			{
				node = tab[a];
				tab[a] = tab[a + 1];
				tab[a + 1] = node;
				b = 1;
			}
			a++;
		}
	}
}
