/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 07:36:21 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/04 14:10:17 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_rotation(int count, t_list *list);

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

void	fill_a(t_list *list)
{
	t_node	*temp;
	int		count;

	temp = list->a;
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
		temp = last_node(list->a);
		while (temp->next->index < list->b->index
			|| temp->index > list->b->index)
		{
			temp = temp->next;
			count++;
		}
	}
	make_rotation(count, list);
	push_a(list, list->a, list->b, 1);
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
	make_rotation(count, list);
}

static void	make_rotation(int count, t_list *list)
{
	if (count <= list->a_len / 2)
		while (count-- > 0)
			rol_a(list, 1);
	else
		while (count++ < list->a_len)
			revrol_a(list, 1);
}
