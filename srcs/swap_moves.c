/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:41:46 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/24 16:16:09 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_list *list, t_node *a)
{
	int	temp;

	if (list->a_len >= 2)
	{
		temp = a->value;
		a->value = a->next->value;
		a->next->value = temp;
		return (SA);
	}
	return (0);
}

int	swap_b(t_list *list, t_node *b)
{
	int	temp;

	if (list->a_len >= 2)
	{
		temp = b->value;
		b->value = b->next->value;
		b->next->value = temp;
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
