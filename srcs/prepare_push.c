/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 07:36:21 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/04 07:51:49 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_push_a(t_list *list)
{
	t_node	*temp;
	int		count;

	temp = list->a;
	count = -1;
	while (++count < list->a_len)
	{
		if (temp->index > list->a_max)
			list->a_max = temp->index;
		if (temp->index < list->a_min)
			list->a_min = temp->index;
		temp = temp->next;
	}
}

void	prepare_push_b(t_list *list, t_moves *moves)
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

void	fill_a(t_list *list)
{
	t_node	*temp;
	t_node	*prev;
	int		count;

	temp = list->a;
	prev = list->a;
	count = 0;
	if (list->b->index < list->a_min || list->b->index > list->a_max)
	{
		while (temp->index != list->a_min)
		{
			temp = temp->next;
			count++;
		}
	}
	else
	{
		while (prev->next != list->a)
			prev = prev->next;
		while (temp->index < list->b->index || prev->index > list->b->index)
		{
			prev = prev->next;
			temp = temp->next;
			count++;
		}
	}
	if (count <= list->a_len / 2)
		while (count-- > 0)
			rol_a(list, 0);
	else
		while (count++ < list->a_len)
			revrol_a(list, 0);
	push_a(list, list->a, list->b);
}

void	put_zero_on_top(t_list *list)
{
	t_node	*temp;
	int		count;

	temp = list->a;
	count = 0;
	while (temp->index != 0)
	{
		temp = temp->next;
		count++;
	}
	if (count <= list->a_len / 2)
		while (count-- > 0)
			rol_a(list, 0);
	else
		while (count++ < list->a_len)
			revrol_a(list, 0);
}
