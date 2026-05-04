/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_helpers3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:28:00 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/24 21:09:49 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_node	*new_node(int content)
{
	t_ps_node	*new;

	new = malloc(sizeof(t_ps_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_ps_node	*ft_lstlast(t_ps_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_ps_node **lst, t_ps_node *new)
{
	t_ps_node	*temp;

	if (!lst || !new)
		return ;
	temp = ft_lstlast(*lst);
	if (temp == NULL)
		*lst = new;
	else
		temp->next = new;
}

void	ft_lstadd_front(t_ps_node **lst, t_ps_node *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_ps_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
