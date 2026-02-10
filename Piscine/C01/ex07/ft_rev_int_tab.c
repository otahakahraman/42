/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:15:47 by okahrama          #+#    #+#             */
/*   Updated: 2025/10/12 14:17:02 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	node;
	int i;

	a = 0;
	while (a < size / 2)
	{
		node = tab[a];
		tab[a] = tab[size - 1 - a];
		tab[size - 1 - a] = node;
		a++;
	}

}

int main()
{
	int tab[]={4,5,6,7};
	int size=4;
	ft_rev_int_tab(tab,size);
	int a=0;
	while (size>a)
	{
		printf("%d",tab[a]);
		a++;
	}


}