/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:33:57 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/04 08:40:32 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_moves(t_list *list, t_node *temp, int index, int i);

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
	t_node	*temp;

	temp = list->b;
	b_count = 0;
	if (index > list->b_max || index < list->b_min)
		b_count = count_moves(list, temp, index, 0);
	else
		b_count = count_moves(list, temp, index, 1);
	if (b_count <= list->b_len / 2)
		moves->b_moves = b_count;
	else
		moves->b_moves = -list->b_len + b_count;
	return (moves->b_moves);
}

static int	count_moves(t_list *list, t_node *temp, int index, int i)
{
	int		count;
	t_node	*prev;

	count = 0;
	if (i == 0)
	{
		while (temp->index != list->b_max)
		{
			temp = temp->next;
			count++;
		}
	}
	else
	{
		prev = last_node(temp);
		while (prev->index < index || temp->index > index)
		{
			count++;
			prev = temp;
			temp = temp->next;
		}
	}
	return (count);
}
