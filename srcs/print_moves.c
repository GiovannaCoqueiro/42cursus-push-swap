/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:42:57 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/17 17:45:19 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_moves(t_moves *moves)
{
	size_t	i;

	i = -1;
	while (++i < moves->len)
		print_moves_aux(moves, i);
}

void	print_moves_aux(t_moves *moves, int index)
{
	if (moves->moves[index] == SA)
		ft_printf("sa\n");
	if (moves->moves[index] == SB)
		ft_printf("sb\n");
	if (moves->moves[index] == SS)
		ft_printf("ss\n");
	if (moves->moves[index] == PA)
		ft_printf("pa\n");
	if (moves->moves[index] == PB)
		ft_printf("pb\n");
	if (moves->moves[index] == RA)
		ft_printf("ra\n");
	if (moves->moves[index] == RB)
		ft_printf("rb\n");
	if (moves->moves[index] == RR)
		ft_printf("rr\n");
	if (moves->moves[index] == RRA)
		ft_printf("rra\n");
	if (moves->moves[index] == RRB)
		ft_printf("rrb\n");
	if (moves->moves[index] == RRR)
		ft_printf("rrr\n");
}
