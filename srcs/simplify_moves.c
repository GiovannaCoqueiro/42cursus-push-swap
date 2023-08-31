/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 07:15:43 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/31 13:29:50 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_nbr(int nbr);
static void	reduce_moves(t_moves *moves);

void	simplify_moves(t_moves *moves, int a_moves, int b_moves)
{
	int	total;

	if ((a_moves > 0 && b_moves > 0) || (a_moves < 0 && b_moves < 0))
		total = a_moves + b_moves;
	else
		total = abs_nbr(a_moves) + abs_nbr(b_moves);
	if (abs_nbr(total) < moves->min_moves)
	{
		moves->min_moves = abs_nbr(total);
		moves->ra = 0;
		moves->rb = 0;
		moves->rr = 0;
		moves->rra = 0;
		moves->rrb = 0;
		moves->rrr = 0;
		if (a_moves > 0)
			moves->ra = a_moves;
		else
			moves->rra = abs_nbr(a_moves);
		if (b_moves > 0)
			moves->rb = b_moves;
		else
			moves->rrb = abs_nbr(b_moves);
		reduce_moves(moves);
	}
}

static int	abs_nbr(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static void	reduce_moves(t_moves *moves)
{
	while ((moves->ra && moves->rb) > 0)
	{
		moves->ra--;
		moves->rb--;
		moves->rr++;
	}
	while ((moves->rra && moves->rrb) > 0)
	{
		moves->rra--;
		moves->rrb--;
		moves->rrr++;
	}
}
