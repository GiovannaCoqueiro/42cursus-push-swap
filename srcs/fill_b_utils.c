/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:33:57 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/30 16:48:00 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*moves_init(t_list *list)
{
	t_moves	*moves;

	moves = malloc(sizeof(t_moves));
	if (moves == NULL)
		error_check(4, list);
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->a_moves = list->total_len;
	moves->b_moves = list->total_len;
	moves->min_moves = list->total_len;
	moves->total_moves = 0;
	return (moves);
}

int	take_a_moves(t_list *list, t_moves *moves, int count)
{
	if (count <= list->a_len / 2)
		moves->a_moves = count;
	else
		moves->a_moves = -list->a_len + count;
	return (moves->a_moves);
}

int	take_b_moves(t_list *list, t_moves *moves, int index)
{
	int		b_count;
	int		buffer;
	t_node	*temp;

	temp = list->b;
	buffer = list->total_len;
	b_count = 0;
	if (index > list->b_max || index < list->b_min)
	{
		while (temp->index != list->b_max)
		{
			temp = temp->next;
			b_count++;
		}
	}
	else
	{
		while (b_count++ < list->b_len && buffer != 1)
		{
			if (index - temp->index < buffer)
				buffer = index - temp->index;
			temp = temp->next;
		}
	}
	if (b_count <= list->b_len / 2)
		moves->b_moves = b_count;
	else
		moves->b_moves = -list->b_len + b_count;
	return (moves->b_moves);
}
