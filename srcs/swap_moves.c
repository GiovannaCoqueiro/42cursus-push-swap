/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:41:46 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/26 14:15:21 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_list *list, t_node *a)
{
	int	temp;

	if (list->a_len >= 2)
	{
		temp = a->index;
		a->index = a->next->index;
		a->next->index = temp;
		return (SA);
	}
	return (0);
}

int	swap_b(t_list *list, t_node *b)
{
	int	temp;

	if (list->a_len >= 2)
	{
		temp = b->index;
		b->index = b->next->index;
		b->next->index = temp;
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
