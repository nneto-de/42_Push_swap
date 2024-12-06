/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:41:10 by nneto-de          #+#    #+#             */
/*   Updated: 2023/10/03 11:41:10 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int	check_sorted(t_ptr **stack_a)
{
	t_list	*a_node;

	a_node = (*stack_a)->next;
	while ((a_node->value) < (a_node->next->value))
		a_node = a_node->next;
	if (a_node == (*stack_a)->next->prev)
		return (0);
	return (1);
}

void	sort(t_ptr **stack_a, t_ptr **stack_b, int argc)
{
	if (argc == 3)
		small_sort_2(stack_a);
	else if (argc == 4)
		small_sort_3(stack_a);
	else
	{
		push(stack_a, stack_b);
		push(stack_a, stack_b);
		big_sort(stack_a, stack_b);
	}
}

void	small_sort_2(t_ptr **stack)
{
	int	a;
	int	b;

	a = (*stack)->next->value;
	b = (*stack)->next->next->value;
	if (a > b)
		swap_stack(stack);
	else
		return ;
}

void	small_sort_3(t_ptr **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->next->value;
	b = (*stack)->next->next->value;
	c = (*stack)->next->next->next->value;
	if (a < b && b < c && a < c)
		return ;
	else if (a < b && b > c && a < c)
	{
		reverse_rotate_stack(stack);
		swap_stack(stack);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_stack(stack);
	else if (a > b && b > c && a > c)
	{
		swap_stack(stack);
		reverse_rotate_stack(stack);
	}
	else if (a > b && b < c && a > c)
		rotate_stack(stack);
	else
		swap_stack(stack);
}

void	big_sort(t_ptr **stack_a, t_ptr **stack_b)
{
	t_ptr	*node_to_push;

	while ((*stack_a)->length > 3)
	{
		reset_stacks(stack_a, stack_b, (*stack_a)->length, (*stack_b)->length);
		find_position_b(stack_a, stack_b, (*stack_a)->length);
		movement_cost(stack_a, (*stack_a)->length);
		node_to_push = get_min_cost_node(*stack_a);
		rotate_pattern(&node_to_push, stack_a, stack_b);
		free(node_to_push);
		push(stack_a, stack_b);
	}
	small_sort_3(stack_a);
	while ((*stack_b)->length > 0)
	{
		reset_stacks(stack_a, stack_b, (*stack_a)->length, (*stack_b)->length);
		find_position_a(stack_a, stack_b, (*stack_b)->length);
		rotate_back_pattern(stack_a, stack_b);
		if ((*stack_b)->length != 0)
			push(stack_b, stack_a);
	}
	reset_stacks(stack_a, stack_a, (*stack_a)->length, (*stack_a)->length);
	final_rotate_back(stack_a, (*stack_a)->next, (*stack_a)->length);
}
