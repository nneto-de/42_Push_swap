/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:13:20 by nneto-de          #+#    #+#             */
/*   Updated: 2023/10/24 14:32:13 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// Creates rotation instructions
t_instruct	*create_instruction(t_instruct *instruction)
{
	instruction = (t_instruct *)malloc(sizeof(t_instruct));
	if (!instruction)
		return (NULL);
	instruction->a = 0;
	instruction->b = 0;
	instruction->both = 0;
	return (instruction);
}

void	rotate_back_pattern(t_ptr **stack_a, t_ptr **stack_b)
{
	int		min_move;

	if (((*stack_b)->next->target) <= ((*stack_b)->next->rev_target))
	{
		min_move = (*stack_b)->next->target;
		while (min_move--)
			rotate_stack(stack_a);
	}
	else
	{
		min_move = (*stack_b)->next->rev_target;
		while (min_move--)
			reverse_rotate_stack(stack_a);
	}
}

void	rotate_back_and_push(t_ptr **stack_a, t_ptr **stack_b)
{
	int	min_move;

	if ((*stack_b)->next->target <= (*stack_b)->next->rev_target)
	{
		min_move = ((*stack_b)->next->target);
		while (min_move--)
			rotate_stack(stack_a);
	}
	else
	{
		min_move = ((*stack_b)->next->rev_target);
		while (min_move--)
			reverse_rotate_stack(stack_a);
	}
	push(stack_b, stack_a);
}

void	final_rotate_back(t_ptr **stack_a, t_list *temp_node, int length)
{
	t_ptr	*min_node;
	int		min_move;

	min_node = (t_ptr *)malloc(sizeof(t_ptr));
	if (!min_node)
		return ;
	while (length--)
	{
		if (temp_node->value > temp_node->next->value)
			min_node->next = temp_node;
		temp_node = temp_node->next;
	}
	if (min_node->next->position <= min_node->next->rev_position)
	{
		min_move = min_node->next->position + 1;
		while ((min_move)--)
			rotate_stack(stack_a);
	}
	else
	{
		min_move = min_node->next->rev_position - 1;
		while ((min_move)--)
			reverse_rotate_stack(stack_a);
	}
	free(min_node);
}
