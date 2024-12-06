/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:28:04 by nneto-de          #+#    #+#             */
/*   Updated: 2023/09/01 19:28:04 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atol(char *argument)
{
	int			sign;
	long		n;

	n = 0;
	sign = 1;
	if (*argument == '-' || *argument == '+')
	{
		if (*argument == '-')
			sign = -sign;
		argument++;
	}
	while (*argument >= '0' && *argument <= '9')
	{
		n = n * 10 + *argument - '0';
		argument++;
	}
	return (n * sign);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(*argv) == 0)
		return (0);
	while (argv[i])
	{
		if ((argv[i][j] == '+' || argv[i][j] == '-') && argv[i][j + 1])
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	check_duplicates(t_list *starting_node)
{
	t_list	*current_node;
	t_list	*copy_node;

	copy_node = starting_node;
	while (copy_node->next)
	{
		current_node = copy_node->next;
		while (current_node)
		{
			if (copy_node->value == current_node->value)
			{
				ft_lstclear(starting_node);
				return (0);
			}
			if (current_node->next)
				current_node = current_node->next;
			else
				break ;
		}
		copy_node = copy_node->next;
	}
	return (1);
}
