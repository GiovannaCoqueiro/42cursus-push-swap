/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:43:32 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/28 15:09:55 by gcoqueir         ###   ########.fr       */
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
	t_moves	*moves;

	if (list->a_len == 2)
		swap_a(list, list->a);
	else if (list->a_len == 3)
		while (is_sorted(list) == 0)
			sort_three(list, list->a);
	else
	{
		if (list->a_len >= 5)
		{
			while (list->a->index >= list->a_len - 3)
				rol_a(list, list->a);
			push_b(list, list->a, list->b);
		}
		while (list->a->index >= list->a_len - 3)
			rol_a(list, list->a);
		push_b(list, list->a, list->b);
		moves = moves_init(list);
		while (list->a_len > 3)
			fill_b(list, list->moves, list->a, list->b);
		while (is_sorted(list) == 0)
			sort_three(list, list->a);
		while (list->b_len > 0)
			fill_a(list, list->a, list->b);
	}
}

void	sort_three(t_list *list, t_node *node)
{
	t_node	*temp;

	temp = node;
	if (temp->index > temp->next->index && temp->next->index
		< temp->next->next->index && temp->index > temp->next->next->index)
		rol_a(list, node);
	else if (temp->index > temp->next->index)
		swap_a(list, node);
	else
		revrol_a(list, node);
}

t_moves	*moves_init(t_list *list)
{
	t_moves	*moves;

	moves = malloc(sizeof(t_moves));
	if (moves == NULL)
		error_check(4, list);
	list->moves->ra = 0;
	list->moves->rb = 0;
	list->moves->rr = 0;
	list->moves->rra = 0;
	list->moves->rrb = 0;
	list->moves->rrr = 0;
	list->moves->a_moves = 0;
	list->moves->b_moves = 0;
	list->moves->min_moves = 0;
	list->moves->total_moves = 0;
}

void	fill_b(t_list *list, t_moves *moves, t_node *a, t_node *b)
{
	int		a_count;
	int		b_count;
	t_node	*temp;

	a_count = -1;
	while (++a_count < list->a_len)
	{
		temp = list->a;
		b_count = -1;
		while (++b_count < list->b_len)
		{
			if (list
		}
	}
	push_b(list, a, b);
}

void	fill_a(t_list *list, t_node *a, t_node *b)
{
	push_a(list, a, b);
}
