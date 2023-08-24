/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:41:46 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/24 09:24:34 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_list *list, t_node *a)
{
	t_node	*temp;
	t_node	*temp2;
	t_node	*iter;

	if (list->a_len >= 2)
	{
		temp = a;
		temp2 = a->next;
		iter = a;
		while (iter->next != a)
			iter = iter->next;
		a->next = a;
		a = temp2;
		iter->next = temp;
		return (SA);
	}
	return (0);
}

int	swap_b(t_list *list, t_node *b)
{
	t_node	*temp;
	t_node	*temp2;
	t_node	*iter;

	if (list->b_len >= 2)
	{
		temp = b;
		temp2 = b->next;
		iter = b;
		while (iter->next != b)
			iter = iter->next;
		b->next = b;
		b = temp;
		iter->next = temp;
		return (SB);
	}
	return (0);
}

int	swap_swap(t_list *list)
{
	if (list->a_len >= 2 && list->b_len >= 2)
	{
		swap_a(list, list->a);
		swap_b(list, list->b);
		return (SS);
	}
	return (0);
}
