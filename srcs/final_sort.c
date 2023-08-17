/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:43:43 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/17 16:37:40 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_stack *stack)
{
	int	sorted;

	stack->moves->moves = NULL;
	stack->moves->len = 0;
	stack->moves->index = -1;
	sorted = 0;
	while (is_sorted(stack) == 0 || stack->b_len != 0)
	{
		next_moves(stack, stack->moves);
	}
}

int	is_sorted(t_stack *stack)
{
	size_t	i;

	i = -1;
	while (++i < stack->a_len - 1)
		if (stack->a[i] > stack->a[i + 1])
			return (0);
	return (1);
}
