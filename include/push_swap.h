/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:54:55 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/22 12:32:47 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define INTMAX 2147483647
# define INTMIN -2147483648


enum e_move
{
	SA = 1,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};

typedef struct s_moves
{
	int		*moves;
	size_t	len;
	int		index;
}	t_moves;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	size_t	a_len;
	size_t	b_len;
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*copy;
	t_moves	*moves;
}	t_stack;

void	check_params(int list, char **param);
t_node	*create_stack(int range, char **param);
t_node	*new_node(long nbr);
void	insertion_sort(int *tab, int range);
void	put_index(int *tab, int *copy, int range);

void	final_sort(t_stack *stack);
int		is_sorted(t_stack *stack);

void	first_moves(t_stack *stack, t_moves *moves);
void	just_three(t_stack *stack, t_moves *moves);
int		*alloc_moves(t_moves *moves, int len);

void	print_moves(t_moves *moves);
void	print_moves_aux(t_moves *moves, int index);

int		swap_a(t_stack *stack);
int		swap_b(t_stack *stack);
int		swap_swap(t_stack *stack);
int		push_a(t_stack *stack);
int		push_b(t_stack *stack);
int		rol_a(t_stack *stack);
int		rol_b(t_stack *stack);
int		rol_rol(t_stack *stack);
int		revrol_a(t_stack *stack);
int		revrol_b(t_stack *stack);
int		revrol_revrol(t_stack *stack);

void	free_for_finish(t_stack *stack);
void	error_check(int i, t_stack *stack);

#endif