/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:45:29 by nneto-de          #+#    #+#             */
/*   Updated: 2023/09/05 09:45:29 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

t_list	*ft_lstnew(void *value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = *(int *)value;
	node->position = 0;
	node->rev_position = 0;
	node->target = 0;
	node->rev_target = 0;
	node->cost = 0;
	node->pattern = ' ';
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elem;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last_elem = ft_lstlast(*lst);
		new->prev = last_elem;
		last_elem->next = new;
	}
}

void	ft_lstclear(t_list *node)
{
	if (node->next == NULL)
	{
		free(node);
		return ;
	}
	ft_lstclear(node->next);
	free(node);
}

int	create_lkd_list(char **argv, t_list **starting_node)
{
	long	value_from_argument;
	t_list	*current_node;

	value_from_argument = ft_atol(*argv);
	*starting_node = ft_lstnew(&value_from_argument);
	current_node = *starting_node;
	argv++;
	while (*argv)
	{
		value_from_argument = ft_atol(*argv);
		if (value_from_argument > INT_MAX || value_from_argument < INT_MIN)
		{
			if (*starting_node)
				ft_lstclear(*starting_node);
			return (0);
		}
		else
		{
			ft_lstadd_back(starting_node, ft_lstnew(&value_from_argument));
			current_node = current_node->next;
		}
		argv++;
	}
	return (1);
}
