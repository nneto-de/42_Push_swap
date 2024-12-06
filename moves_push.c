/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:15:40 by nneto-de          #+#    #+#             */
/*   Updated: 2023/10/24 14:34:33 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	push_to_0(t_ptr **stack_from, t_ptr **stack_to)
{
	(*stack_to)->next = (*stack_from)->next;
	(*stack_from)->next = (*stack_from)->next->next;
	(*stack_from)->next->prev = ((*stack_to)->next)->prev;
	(*stack_from)->next->prev->next = (*stack_to)->next;
	(*stack_to)->next->next = NULL;
	(*stack_to)->next->prev = NULL;
}

void	push_to_1(t_ptr **stack_from, t_ptr **stack_to)
{
	(*stack_to)->next->prev = (*stack_from)->next;
	(*stack_to)->next->next = (*stack_from)->next;
	(*stack_from)->next = (*stack_from)->next->next;
	(*stack_from)->next->prev = (*stack_from)->next->prev->prev;
	(*stack_from)->next->prev->next = (*stack_from)->next;
	(*stack_to)->next->next->prev = (*stack_to)->next;
	(*stack_to)->next->next->next = (*stack_to)->next;
	(*stack_to)->next = (*stack_to)->next->next;
}

void	push_from_1(t_ptr **stack_from, t_ptr **stack_to)
{
	(*stack_from)->next->next = (*stack_to)->next;
	(*stack_from)->next->prev = (*stack_to)->next->prev;
	(*stack_to)->next->prev->next = (*stack_from)->next;
	(*stack_to)->next->prev = (*stack_from)->next;
	(*stack_to)->next = (*stack_to)->next->prev;
	(*stack_from)->next = NULL;
}

void	push_to_x(t_ptr **stack_from, t_ptr **stack_to)
{
	t_list	*temp_node;

	temp_node = (*stack_from)->next;
	(*stack_from)->next = (*stack_from)->next->next;
	temp_node->next->prev = temp_node->prev;
	temp_node->prev->next = temp_node->next;
	temp_node->next = (*stack_to)->next;
	temp_node->prev = (*stack_to)->next->prev;
	(*stack_to)->next->prev->next = temp_node;
	(*stack_to)->next->prev = temp_node;
	(*stack_to)->next = temp_node;
}

void	push(t_ptr **stack_from, t_ptr **stack_to)
{
	if ((*stack_to)->length == 0)
		push_to_0(stack_from, stack_to);
	else if ((*stack_to)->length == 1)
		push_to_1(stack_from, stack_to);
	else if ((*stack_from)->length == 1)
		push_from_1(stack_from, stack_to);
	else
		push_to_x(stack_from, stack_to);
	((*stack_from)->length)--;
	((*stack_to)->length)++;
	write(1, "p", 1);
	write(1, &(*stack_to)->name, 1);
	write(1, "\n", 1);
}
