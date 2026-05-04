/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:20:30 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/10 17:11:00 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	a;
	int	b;
	int	value;

	value = 0;
	a = 0;
	b = 1;
	while (str[a] != '\0' && !(str[a] >= '0' && str[a] <= '9'))
	{
		if ((str[a] >= 'A' && str[a] <= 'Z') || (str[a] >= 'a'
				&& str[a] <= 'z'))
			return (value * b);
		else if (str[a] == '-')
		{
			b *= -1;
		}
		a++;
	}
	while (str[a] != '\0' && (str[a] >= '0' && str[a] <= '9'))
	{
		value = value * 10 + str[a] - 48;
		a++;
	}
	return (value * b);
}
