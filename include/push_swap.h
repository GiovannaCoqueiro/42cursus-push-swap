/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:54:55 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/05 12:52:16 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define INTMAX 2147483647
# define INTMIN -2147483648

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

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
	int		a_max;
	int		a_min;
	t_node	*b;
	int		b_len;
	int		b_max;
	int		b_min;
	int		total_len;
	char	*cmd;
}	t_list;

void	check_params(int range, char **param);
t_list	*init_list(int range);
t_node	*create_list(t_list *list, int range, char **param);
t_node	*new_node(long nbr);
t_node	*last_node(t_node *node);
void	get_index(int range, char **param, t_list *list);
int		is_sorted(t_list *list);
void	sorting(t_list *list);
void	sort_three(t_list *list, t_node *node);
void	fill_b(t_list *list);
int		take_a_moves(t_list *list, t_moves *moves, int count);
int		take_b_moves(t_list *list, t_moves *moves, int index);
void	simplify_moves(t_moves *moves, int a_moves, int b_moves);
void	prepare_push_a(t_list *list);
void	fill_a(t_list *list);
void	put_zero_on_top(t_list *list);
void	swap_a(t_list *list, t_node *a, int i);
void	swap_b(t_list *list, t_node *b, int i);
void	swap_swap(t_list *list, int i);
void	push_a(t_list *list, t_node *a, t_node *b, int i);
void	push_b(t_list *list, t_node *a, t_node *b, int i);
void	rol_a(t_list *list, int i);
void	rol_b(t_list *list, int i);
void	rol_rol(t_list *list, int i);
void	revrol_a(t_list *list, int i);
void	revrol_b(t_list *list, int i);
void	revrol_revrol(t_list *list, int i);
void	free_for_finish(t_list *list);
void	free_node(t_node **node, int len);
void	error_check(t_list *list);

/*bonus function*/
void	take_instructions(t_list *list);

#endif