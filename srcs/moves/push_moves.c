/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:26:11 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/04 08:21:59 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b_utils(t_list *list, t_node *b, t_node *temp);

int	push_a(t_list *list, t_node *a, t_node *b)
{
	t_node	*temp;
	t_node	*last;

	if (list->b_len >= 1)
	{
		if (list->b->index < list->a_min)
			list->a_min = list->b->index;
		if (list->b->index > list->a_max)
			list->a_max = list->b->index;
		list->a_len++;
		list->b_len--;
		temp = b;
		last = last_node(list->b);
		last->next = list->b->next;
		list->b = last->next;
		last = last_node(list->a);
		last->next = temp;
		temp->next = a;
		list->a = temp;
		ft_printf("pa\n");
		return (PA);
	}
	return (0);
}

int	push_b(t_list *list, t_node *a, t_node *b)
{
	t_node	*temp;
	t_node	*last;

	if (list->a_len >= 1)
	{
		if (list->a->index < list->b_min)
			list->b_min = list->a->index;
		if (list->a->index > list->b_max)
			list->b_max = list->a->index;
		list->b_len++;
		list->a_len--;
		temp = a;
		last = last_node(list->a);
		last->next = list->a->next;
		list->a = last->next;
		push_b_utils(list, b, temp);
		ft_printf("pb\n");
		return (PB);
	}
	return (0);
}

static void	push_b_utils(t_list *list, t_node *b, t_node *temp)
{
	t_node	*last;

	if (b == NULL)
	{
		b = temp;
		b->next = b;
		list->b = b;
	}
	else
	{
		last = last_node(list->b);
		last->next = temp;
		temp->next = b;
		list->b = temp;
	}
}

t_node	*last_node(t_node *node)
{
	t_node	*last;

	last = node;
	while (last->next != node)
		last = last->next;
	return (last);
}
