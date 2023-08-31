/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:43:32 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/31 07:00:42 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	t_node	*temp;

	temp = list->a;
	while (temp->next != list->a)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sorting(t_list *list)
{
	if (list->a_len == 2)
		swap_a(list, list->a);
	else if (list->a_len == 3)
		while (is_sorted(list) == 0)
			sort_three(list, list->a);
	else
	{
		if (list->a_len >= 5)
		{
			while (list->a->index >= list->total_len - 3)
				rol_a(list);
			push_b(list, list->a, list->b);
		}
		while (list->a->index >= list->total_len - 3)
			rol_a(list);
		push_b(list, list->a, list->b);
		while (list->a_len > 3)
			fill_b(list);
		while (is_sorted(list) == 0)
			sort_three(list, list->a);
		prepare_push_a(list);
		while (list->b_len > 0)
			push_a(list, list->a, list->b);
	}
}

void	sort_three(t_list *list, t_node *node)
{
	t_node	*temp;

	temp = node;
	if (temp->index > temp->next->index && temp->next->index
		< temp->next->next->index && temp->index > temp->next->next->index)
		rol_a(list);
	else if (temp->index > temp->next->index)
		swap_a(list, node);
	else
		revrol_a(list);
}

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
		if (temp->index < list->total_len - 3)
		{
			buffer_a = take_a_moves(list, moves, a_count);
			buffer_b = take_b_moves(list, moves, temp->index);
			simplify_moves(moves, buffer_a, buffer_b);
		}
		temp = temp->next;
	}
	prepare_push_b(list, moves);
	push_b(list, list->a, list->b);
	free(moves);
}

void	prepare_push_a(t_list *list)
{
	int		index;
	t_node	*temp;

	index = -1;
	temp = list->b;
	while (++index < list->b_len)
	{
		if (temp->index == list->a->index - 1)
			break ;
		temp = temp->next;
	}
	if (index <= list->b_len / 2)
		while (index-- > 0)
			rol_b(list);
	else
		while (index++ < list->b_len)
			revrol_b(list);
}

void	prepare_push_b(t_list *list, t_moves *moves)
{
	while (moves->ra-- > 0)
		rol_a(list);
	while (moves->rra-- > 0)
		revrol_a(list);
	while (moves->rb-- > 0)
		rol_b(list);
	while (moves->rrb-- > 0)
		revrol_b(list);
}
