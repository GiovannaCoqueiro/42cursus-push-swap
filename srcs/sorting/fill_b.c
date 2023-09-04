/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:38:12 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/04 08:39:40 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_moves	*moves_init(t_list *list);
static void		prepare_push_b(t_list *list, t_moves *moves);

void	fill_b(t_list *list)
{
	int		a_count;
	int		buffer_a;
	int		buffer_b;
	t_moves	*moves;
	t_node	*temp;

	moves = moves_init(list);
	a_count = -1;
	temp = list->a;
	while (++a_count < list->a_len)
	{
		buffer_a = take_a_moves(list, moves, a_count);
		buffer_b = take_b_moves(list, moves, temp->index);
		simplify_moves(moves, buffer_a, buffer_b);
		temp = temp->next;
	}
	prepare_push_b(list, moves);
	push_b(list, list->a, list->b);
	free(moves);
}

static t_moves	*moves_init(t_list *list)
{
	t_moves	*moves;

	moves = malloc(sizeof(t_moves));
	if (moves == NULL)
		error_check(list);
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->a_moves = list->total_len;
	moves->b_moves = list->total_len;
	moves->min_moves = list->total_len;
	moves->total_moves = 0;
	return (moves);
}

static void	prepare_push_b(t_list *list, t_moves *moves)
{
	while (moves->ra-- > 0)
		rol_a(list, 0);
	while (moves->rb-- > 0)
		rol_b(list, 0);
	while (moves->rr-- > 0)
		rol_rol(list);
	while (moves->rra-- > 0)
		revrol_a(list, 0);
	while (moves->rrb-- > 0)
		revrol_b(list, 0);
	while (moves->rrr-- > 0)
		revrol_revrol(list);
}
