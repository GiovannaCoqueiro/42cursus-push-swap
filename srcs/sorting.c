/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:43:32 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/29 09:00:15 by gcoqueir         ###   ########.fr       */
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
			while (list->a->index >= list->a_len - 3)
				rol_a(list, list->a);
			push_b(list, list->a, list->b);
		}
		while (list->a->index >= list->a_len - 2)
			rol_a(list, list->a);
		push_b(list, list->a, list->b);
		while (list->a_len > 3)
			fill_b(list, list->a, list->b);
		while (is_sorted(list) == 0)
			sort_three(list, list->a);
		prepare_push_a(list, list->b);
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
	return (moves);
}

void	fill_b(t_list *list, t_node *a, t_node *b)
{
	// int		a_count;
	// int		b_count;
	// t_node	*temp;
	// t_moves	*moves;

	// moves = moves_init(list);
	// a_count = -1;
	// temp = list->a;
	// while (++a_count < list->a_len)
	// {
	// 	b_count = -1;
	// 	if (temp->index < list->a_len - 3)
	// 	{
	// 		if (a_count <= list->a_len / 2)
	// 		{
	// 			moves->ra = a_count;
	// 			while (++b_count < list->b_len)
	// 			{
					
	// 			}
	// 		}
	// 		else
	// 			moves->rra = list->a_len - a_count;
	// 	}
	// }
	push_b(list, a, b);
	// free(moves);
}

void	prepare_push_a(t_list *list, t_node *b)
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
			rol_b(list, b);
	else
		while (index++ < list->b_len)
			revrol_b(list, b);
}
