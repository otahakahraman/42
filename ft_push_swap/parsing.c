/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:58:31 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/26 16:41:49 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	control(char *nptr)
{
	int	i;
	int	sign;

	i = 0;
	if (!nptr || nptr[i] == '\0')
		return (0);
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	return (parse_digits(nptr, i, sign));
}

t_ps_node	*parse_control(int argc, char **argv, t_count *counter)
{
	t_ps_node	*new_list;

	is_flag(argv, counter);
	new_list = NULL;
	while (counter->size < argc)
	{
		if (ft_strchr(argv[counter->size], ' '))
		{
			if (!handle_split(argv[counter->size], &new_list))
				return (free_list(new_list), NULL);
		}
		else
		{
			if (!handle_single(argv[counter->size], &new_list))
				return (free_list(new_list), NULL);
		}
		counter->size++;
	}
	if (dup_number(new_list) == 1)
		return (free_list(new_list), NULL);
	counter->numb_size = ft_lstsize(new_list);
	return (new_list);
}

int	dup_number(t_ps_node *new_list)
{
	t_ps_node	*temp;

	while (new_list)
	{
		temp = new_list->next;
		while (temp)
		{
			if (temp->content == new_list->content)
				return (1);
			temp = temp->next;
		}
		new_list = new_list->next;
	}
	return (0);
}

void	is_flag(char **argv, t_count *counter)
{
	counter->size = 1;
	if ((argv[1] != NULL) && (ft_strcmp(argv[1], "--bench") == 0))
	{
		counter->size = 2;
		if ((argv[2] != NULL) && ((ft_strcmp(argv[2], "--simple") == 0)
				|| (ft_strcmp(argv[2], "--medium") == 0) || (ft_strcmp(argv[2],
						"--complex") == 0) || (ft_strcmp(argv[2],
						"--adaptive") == 0)))
		{
			counter->size = 3;
		}
	}
	else if ((argv != NULL) && (argv[1] != NULL) && ((ft_strcmp(argv[1],
					"--simple") == 0) || (ft_strcmp(argv[1], "--medium") == 0)
			|| (ft_strcmp(argv[1], "--complex") == 0) || (ft_strcmp(argv[1],
					"--adaptive") == 0)))
	{
		counter->size = 2;
		if ((argv[2] != NULL) && (ft_strcmp(argv[2], "--bench") == 0))
		{
			counter->size = 3;
		}
	}
	counter->numb_size = counter->size;
	algorithm_selection(counter, argv);
}

void	algorithm_selection(t_count *counter, char **argv)
{
	counter->alg_numb = 0;
	if (((argv[1] != NULL && ft_strcmp(argv[1], "--simple") == 0))
		|| ((argv[2] != NULL && ft_strcmp(argv[2], "--simple") == 0)))
		counter->alg_numb = 1;
	else if ((argv[1] != NULL && ft_strcmp(argv[1], "--medium") == 0)
		|| (argv[2] != NULL && ft_strcmp(argv[2], "--medium") == 0))
		counter->alg_numb = 2;
	else if ((argv[1] != NULL && ft_strcmp(argv[1], "--complex") == 0)
		|| (argv[2] != NULL && ft_strcmp(argv[2], "--complex") == 0))
		counter->alg_numb = 3;
	else if ((argv[1] != NULL && ft_strcmp(argv[1], "--adaptive") == 0)
		|| (argv[2] != NULL && ft_strcmp(argv[2], "--adaptive") == 0))
		counter->alg_numb = 4;
}
