/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:41:46 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/16 17:32:09 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_stack *stack)
{
	int	temp;

	if (stack->a_len >= 2)
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
		return (1);
	}
	return (0);
}

int	swap_b(t_stack *stack)
{
	int	temp;

	if (stack->b_len >= 2)
	{
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
		return (1);
	}
	return (0);
}

int	swap_swap(t_stack *stack)
{
	if (swap_a(stack) != 0 && swap_b(stack) != 0)
		return (1);
	return (0);
}
