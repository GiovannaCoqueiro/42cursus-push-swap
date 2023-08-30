/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:26:11 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/30 16:12:13 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b_utils(t_list *list, t_node *b, t_node *temp);

int	push_a(t_list *list, t_node *a, t_node *b)
{
	t_node	*temp;
	t_node	*iter;

	if (list->b_len >= 1)
	{
		list->a_len++;
		list->b_len--;
		temp = b;
		iter = list->b;
		while (iter->next != b)
			iter = iter->next;
		iter->next = list->b->next;
		list->b = iter->next;
		iter = a;
		while (iter->next != a)
			iter = iter->next;
		iter->next = temp;
		temp->next = a;
		list->a = temp;
		return (PA);
	}
	return (0);
}

int	push_b(t_list *list, t_node *a, t_node *b)
{
	t_node	*temp;
	t_node	*iter;

	if (list->a_len >= 1)
	{
		if (list->a->index < list->b_min)
			list->b_min = list->a->index;
		if (list->a->index > list->b_max)
			list->b_max = list->a->index;
		list->b_len++;
		list->a_len--;
		temp = a;
		iter = list->a;
		while (iter->next != a)
			iter = iter->next;
		iter->next = list->a->next;
		list->a = iter->next;
		push_b_utils(list, b, temp);
		return (PB);
	}
	return (0);
}

static void	push_b_utils(t_list *list, t_node *b, t_node *temp)
{
	t_node	*iter;

	if (b == NULL)
	{
		b = temp;
		b->next = b;
		list->b = b;
	}
	else
	{
		iter = b;
		while (iter->next != b)
			iter = iter->next;
		iter->next = temp;
		temp->next = b;
		list->b = temp;
	}
}
