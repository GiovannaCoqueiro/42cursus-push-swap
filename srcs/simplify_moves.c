/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 07:15:43 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/31 07:16:30 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_nbr(int nbr);

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

static int	abs_nbr(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}
