/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 07:36:21 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/31 07:38:50 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_push_a(t_list *list)
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
			rol_b(list);
	else
		while (index++ < list->b_len)
			revrol_b(list);
}

void	prepare_push_b(t_list *list, t_moves *moves)
{
	while (moves->ra-- > 0)
		rol_a(list);
	while (moves->rb-- > 0)
		rol_b(list);
	while (moves->rr-- > 0)
		rol_rol(list);
	while (moves->rra-- > 0)
		revrol_a(list);
	while (moves->rrb-- > 0)
		revrol_b(list);
	while (moves->rrr-- > 0)
		revrol_revrol(list);
}
