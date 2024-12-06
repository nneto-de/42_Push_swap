/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:45:31 by nneto-de          #+#    #+#             */
/*   Updated: 2023/10/24 14:34:53 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_stack(t_ptr **stack)
{
	swap(&(*stack)->next->value, &(*stack)->next->next->value);
	write(1, "s", 1);
	write(1, &(*stack)->name, 1);
	write(1, "\n", 1);
}

void	swap_both(t_ptr **stack_a, t_ptr **stack_b)
{
	swap(&(*stack_a)->next->value, &(*stack_a)->next->next->value);
	swap(&(*stack_b)->next->value, &(*stack_b)->next->next->value);
	write(1, "ss\n", 3);
}
