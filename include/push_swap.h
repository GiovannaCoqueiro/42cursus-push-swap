/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:54:55 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/29 09:46:08 by gcoqueir         ###   ########.fr       */
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
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		a_moves;
	int		b_moves;
	int		total_moves;
	int		min_moves;
}	t_moves;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*a;
	int		a_len;
	t_node	*b;
	int		b_len;
	t_moves	*moves;
}	t_list;

void	check_params(int range, char **param);
t_list	*init_list(void);
t_node	*create_list(t_list *list, int range, char **param);
void	get_index(int range, char **param, t_list *list);
int		is_sorted(t_list *list);
void	sorting(t_list *list);
void	sort_three(t_list *list, t_node *node);
t_moves	*moves_init(t_list *list);
void	fill_b(t_list *list, t_node *a, t_node *b);
void	prepare_push_a(t_list *list);

int		swap_a(t_list *list, t_node *a);
int		swap_b(t_list *list, t_node *b);
int		swap_swap(t_list *list);
int		push_a(t_list *list, t_node *a, t_node *b);
int		push_b(t_list *list, t_node *a, t_node *b);
int		rol_a(t_list *list);
int		rol_b(t_list *list);
int		rol_rol(t_list *list);
int		revrol_a(t_list *list);
int		revrol_b(t_list *list);
int		revrol_revrol(t_list *list);

void	free_for_finish(t_list *list);
void	free_node(t_node **node, int len);
void	error_check(int i, t_list *list);

#endif