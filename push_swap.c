/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:50:30 by nneto-de          #+#    #+#             */
/*   Updated: 2023/09/01 19:50:30 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include <limits.h>

int	main(int argc, char **argv)
{
	t_list			*starting_node;
	t_ptr			*stack_a;
	t_ptr			*stack_b;

	if (argc < 2)
		return (1);
	++argv;
	if ((argc == 2 && (ft_atol(*argv) > INT_MAX || ft_atol(*argv) < INT_MIN))
		|| check_args(argv) == 0 || create_lkd_list(argv, &starting_node) == 0
		|| check_duplicates(starting_node) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	create_stacks(&starting_node, &stack_a, &stack_b, argc - 1);
	if (check_sorted(&stack_a) == 0)
	{
		free_allocs(&stack_a, &stack_b);
		return (0);
	}
	sort(&stack_a, &stack_b, argc);
	free_allocs(&stack_a, &stack_b);
	return (0);
}
