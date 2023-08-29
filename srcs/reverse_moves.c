/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 06:44:41 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/29 09:44:10 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	revrol_a(t_list *list)
{
	t_node	*temp;

	temp = list->a;
	if (list->a_len >= 2)
	{
		while (list->a->next != temp)
			list->a = list->a->next;
		return (RRA);
	}
	return (0);
}

int	revrol_b(t_list *list)
{
	t_node	*temp;

	temp = list->b;
	if (list->b_len >= 2)
	{
		while (list->b->next != temp)
			list->b = list->b->next;
		return (RRB);
	}
	return (0);
}

int	revrol_revrol(t_list *list)
{
	if (list->a_len >= 2 && list->b_len >= 2)
	{
		revrol_a(list);
		revrol_b(list);
		return (RRR);
	}
	return (0);
}
