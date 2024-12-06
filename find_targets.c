/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_targets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:12:40 by nneto-de          #+#    #+#             */
/*   Updated: 2023/10/24 14:34:02 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	find_position_b(t_ptr **stack_a, t_ptr **stack_b, int length_a)
{
	t_list	*a_node;
	t_list	*b_node;
	int		length_b;
	int		tmp_max;

	a_node = (*stack_a)->next;
	while (length_a--)
	{
		length_b = (*stack_b)->length;
		b_node = (*stack_b)->next;
		tmp_max = INT_MIN;
		while (length_b--)
		{
			if (a_node->value > b_node->value && b_node->value >= tmp_max)
			{
				a_node->target = b_node->position;
				a_node->rev_target = b_node->rev_position;
				tmp_max = b_node->value;
			}
			b_node = b_node->next;
		}
		if (a_node->target == 0 && a_node->value < (*stack_b)->next->value)
			min_targets(&a_node, stack_b);
		a_node = a_node->next;
	}
}

void	find_position_a(t_ptr **stack_a, t_ptr **stack_b, int length_b)
{
	t_list	*a_node;
	t_list	*b_node;
	int		length_a;
	int		tmp_max;

	b_node = (*stack_b)->next;
	while (length_b--)
	{
		length_a = (*stack_a)->length;
		a_node = (*stack_a)->next;
		tmp_max = INT_MAX;
		while (length_a--)
		{
			if (a_node->value > b_node->value && a_node->value <= tmp_max)
			{
				b_node->target = a_node->position;
				b_node->rev_target = a_node->rev_position;
				tmp_max = a_node->value;
			}
			a_node = a_node->next;
		}
		if (b_node->target == 0 && b_node->value > (*stack_a)->next->value)
			max_targets(&b_node, stack_a);
		b_node = b_node->next;
	}
}

void	max_targets(t_list **node, t_ptr **stack)
{
	t_list	*tmp_node;

	tmp_node = (*stack)->next;
	while (tmp_node->next->value > tmp_node->value)
		tmp_node = tmp_node->next;
	(*node)->target = tmp_node->position + 1;
	(*node)->rev_target = tmp_node->rev_position - 1;
}

void	min_targets(t_list **node, t_ptr **stack)
{
	t_list	*tmp_node;

	tmp_node = (*stack)->next;
	while (tmp_node->next->value < tmp_node->value)
		tmp_node = tmp_node->next;
	(*node)->target = tmp_node->position + 1;
	(*node)->rev_target = tmp_node->rev_position - 1;
}
