/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_moves2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:49:44 by nneto-de          #+#    #+#             */
/*   Updated: 2023/10/24 14:35:50 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	rotate_pattern(t_ptr **node, t_ptr **stack_a, t_ptr **stack_b)
{
	if ((*node)->next->cost == 1)
		return ;
	if ((*node)->next->pattern == 'a')
		calc_rotate_a_up_b_up(node, stack_a, stack_b);
	else if ((*node)->next->pattern == 'b')
		calc_rotate_a_down_b_down(node, stack_a, stack_b);
	else if ((*node)->next->pattern == 'c')
		calc_rotate_a_up_b_down(node, stack_a, stack_b);
	else
		calc_rotate_a_down_b_up(node, stack_a, stack_b);
}

void	calc_rotate_a_up_b_up(t_ptr **node, t_ptr **stack_a, t_ptr **stack_b)
{
	t_instruct	*rotate_instruct;

	rotate_instruct = NULL;
	rotate_instruct = create_instruction(rotate_instruct);
	if ((*node)->next->position > (*node)->next->target)
	{
		rotate_instruct->a = (*node)->next->position - (*node)->next->target;
		rotate_instruct->both = (*node)->next->target;
	}
	else if ((*node)->next->position < (*node)->next->target)
	{
		rotate_instruct->b = (*node)->next->target - (*node)->next->position;
		rotate_instruct->both = (*node)->next->position;
	}
	else
		rotate_instruct->both = (*node)->next->target;
	rotate(&rotate_instruct, stack_a, stack_b);
	free(rotate_instruct);
}

void	calc_rotate_a_down_b_down(t_ptr **node, t_ptr **stack_a,
		t_ptr **stack_b)
{
	t_instruct	*rotate_instruct;

	rotate_instruct = NULL;
	rotate_instruct = create_instruction(rotate_instruct);
	if ((*node)->next->rev_position > (*node)->next->rev_target)
	{
		rotate_instruct->a = -((*node)->next->rev_position
				- (*node)->next->rev_target);
		rotate_instruct->both = - (*node)->next->rev_target;
	}
	else if ((*node)->next->rev_position < (*node)->next->rev_target)
	{
		rotate_instruct->b = - ((*node)->next->rev_target
				- (*node)->next->rev_position);
		rotate_instruct->both = - (*node)->next->rev_position;
	}
	else
		rotate_instruct->both = -(*node)->next->rev_target;
	rotate(&rotate_instruct, stack_a, stack_b);
	free(rotate_instruct);
}

void	calc_rotate_a_up_b_down(t_ptr **node, t_ptr **stack_a,
		t_ptr **stack_b)
{
	t_instruct	*rotate_instruct;

	rotate_instruct = NULL;
	rotate_instruct = create_instruction(rotate_instruct);
	rotate_instruct->a = (*node)->next->position;
	rotate_instruct->b = - (*node)->next->rev_target;
	rotate(&rotate_instruct, stack_a, stack_b);
	free(rotate_instruct);
}

void	calc_rotate_a_down_b_up(t_ptr **node, t_ptr **stack_a,
		t_ptr **stack_b)
{
	t_instruct	*rotate_instruct;

	rotate_instruct = NULL;
	rotate_instruct = create_instruction(rotate_instruct);
	rotate_instruct->a = - (*node)->next->rev_position;
	rotate_instruct->b = (*node)->next->target;
	rotate(&rotate_instruct, stack_a, stack_b);
	free(rotate_instruct);
}
