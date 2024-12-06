/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:36:41 by nneto-de          #+#    #+#             */
/*   Updated: 2023/10/03 15:36:41 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rotate_stack(t_ptr **stack)
{
	(*stack)->next = (*stack)->next->next;
	write(1, "r", 1);
	write(1, &(*stack)->name, 1);
	write(1, "\n", 1);
}

void	rotate_both(t_ptr **stack_a, t_ptr **stack_b)
{
	(*stack_a)->next = (*stack_a)->next->next;
	(*stack_b)->next = (*stack_b)->next->next;
	write(1, "rr\n", 3);
}

void	reverse_rotate_stack(t_ptr **stack)
{
	(*stack)->next = (*stack)->next->prev;
	write(1, "rr", 2);
	write(1, &(*stack)->name, 1);
	write(1, "\n", 1);
}

void	reverse_rotate_both(t_ptr **stack_a, t_ptr **stack_b)
{
	(*stack_a)->next = (*stack_a)->next->prev;
	(*stack_b)->next = (*stack_b)->next->prev;
	write(1, "rrr\n", 4);
}

void	rotate(t_instruct **rotate_instruct, t_ptr **stack_a,
	t_ptr **stack_b)
{
	while ((*rotate_instruct)->a-- > 0)
		rotate_stack(stack_a);
	while ((*rotate_instruct)->b-- > 0)
		rotate_stack(stack_b);
	while ((*rotate_instruct)->both-- > 0)
		rotate_both(stack_a, stack_b);
	(*rotate_instruct)->a++;
	(*rotate_instruct)->b++;
	(*rotate_instruct)->both++;
	while ((*rotate_instruct)->a++ < 0)
		reverse_rotate_stack(stack_a);
	while ((*rotate_instruct)->b++ < 0)
		reverse_rotate_stack(stack_b);
	while ((*rotate_instruct)->both++ < 0)
		reverse_rotate_both(stack_a, stack_b);
	(*rotate_instruct)->a--;
	(*rotate_instruct)->b--;
	(*rotate_instruct)->both--;
}
