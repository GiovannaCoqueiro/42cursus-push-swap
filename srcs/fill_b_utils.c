/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:33:57 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/31 06:56:44 by gcoqueir         ###   ########.fr       */
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
	t_node	*prev;

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
		prev = temp;
		while (prev->next != temp)
			prev = prev->next;
		while (prev->index < index || temp->index > index)
		{
			b_count++;
			prev = temp;
			temp = temp->next;
		}
	}
	if (b_count <= list->b_len / 2)
		moves->b_moves = b_count;
	else
		moves->b_moves = -list->b_len + b_count;
	return (moves->b_moves);
}

void	simplify_moves(t_moves *moves, int a_moves, int b_moves)
{
	int	total;
	int	total_buffer;

	if ((a_moves > 0 && b_moves > 0) || (a_moves < 0 && b_moves < 0))
		total = a_moves + b_moves;
	else
		total = abs_nbr(a_moves) + abs_nbr(b_moves);
	total_buffer = abs_nbr(total);
	if (total_buffer < moves->min_moves)
	{
		moves->min_moves = total_buffer;
		moves->ra = 0;
		moves->rra = 0;
		moves->rb = 0;
		moves->rrb = 0;
		if (a_moves > 0)
			moves->ra = a_moves;
		else
			moves->rra = abs_nbr(a_moves);
		if (b_moves > 0)
			moves->rb = b_moves;
		else
			moves->rrb = abs_nbr(b_moves);
	}
}

int	abs_nbr(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}
