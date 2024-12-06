/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:46:40 by nneto-de          #+#    #+#             */
/*   Updated: 2023/09/05 09:46:40 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				value;
	int				position;
	int				rev_position;
	int				target;
	int				rev_target;
	int				cost;
	char			pattern;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_ptr
{
	char			name;
	int				length;
	t_list			*next;
}	t_ptr;

typedef struct s_cost
{
	int		a_up_b_up;
	int		a_down_b_down;
	int		a_up_b_down;
	int		a_down_b_up;
	char	course;
}	t_cost;

typedef struct s_instruct
{
	int		a;
	int		b;
	int		both;
}	t_instruct;

// Main.c
int			main(int argc, char **argv);

// Validate_create_linked_list.c
int			ft_isdigit(char c);
long		ft_atol(char *argument);
int			ft_strlen(char *str);
int			check_args(char **argv);
int			check_duplicates(t_list *starting_node);

// Process_stacks.c
void		create_stacks(t_list **starting_node, t_ptr **stack_a,
				t_ptr **stack_b, int length);
void		reset_stacks(t_ptr **stack_a, t_ptr **stack_b,
				int length_a, int length_b);
void		reset_node(t_list **node, t_ptr **stack, int length);
void		free_allocs(t_ptr **stack_a, t_ptr **stack_b);

// Linked_list_func.c
t_list		*ft_lstnew(void *value);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list *node);
int			create_lkd_list(char **argv, t_list **starting_node);

// Sort.c
int			check_sorted(t_ptr **stack_a);
void		sort(t_ptr **stack_a, t_ptr **stack_b, int argc);
void		small_sort_2(t_ptr **stack);
void		small_sort_3(t_ptr **stack);
void		big_sort(t_ptr **stack_a, t_ptr **stack_b);

// Process_rotates.c
t_instruct	*create_instruction(t_instruct *instruction);
void		rotate_back_pattern(t_ptr **stack_a, t_ptr **stack_b);
void		rotate_back_and_push(t_ptr **stack_a, t_ptr **stack_b);
void		final_rotate_back(t_ptr **stack_a, t_list *temp_node, int length);

// Find_targets.c
void		find_position_b(t_ptr **stack_a, t_ptr **stack_b, int length_a);
void		find_position_a(t_ptr **stack_a, t_ptr **stack_b, int length_a);
void		max_targets(t_list **node, t_ptr **stack);
void		min_targets(t_list **node, t_ptr **stack);

/// Calculate_cost.c
int			min_cost(int a, int b, int c, int d);
int			max_val(int a, int b);
void		calculate_cost(t_list **stack_a, t_cost *cost);
void		movement_cost(t_ptr **stack, int length);
t_ptr		*get_min_cost_node(t_ptr *stack_a);

/// Calculate_move.c
void		rotate_pattern(t_ptr **node, t_ptr **stack_a, t_ptr **stack_b);
void		calc_rotate_a_up_b_up(t_ptr **node, t_ptr **stack_a,
				t_ptr **stack_b);
void		calc_rotate_a_down_b_down(t_ptr **node, t_ptr **stack_a,
				t_ptr **stack_b);
void		calc_rotate_a_up_b_down(t_ptr **node, t_ptr **stack_a,
				t_ptr **stack_b);
void		calc_rotate_a_down_b_up(t_ptr **node, t_ptr **stack_a,
				t_ptr **stack_b);

// Moves.c
/// Moves_rotate.c
void		rotate_stack(t_ptr **stack);
void		rotate_both(t_ptr **stack_a, t_ptr **stack_b);
void		reverse_rotate_stack(t_ptr **stack);
void		reverse_rotate_both(t_ptr **stack_a, t_ptr **stack_b);
void		rotate(t_instruct **rotate_instruct, t_ptr **stack_a,
				t_ptr **stack_b);

/// Moves_swap.c
void		swap_stack(t_ptr **stack);
void		swap_both(t_ptr **stack_a, t_ptr **stack_b);
void		swap(int *a, int *b);

/// Moves_push.c
void		push_to_0(t_ptr **stack_from, t_ptr **stack_to);
void		push_to_1(t_ptr **stack_from, t_ptr **stack_to);
void		push_from_1(t_ptr **stack_from, t_ptr **stack_to);
void		push_to_x(t_ptr **stack_from, t_ptr **stack_to);
void		push(t_ptr **stack_from, t_ptr **stack_to);

#endif