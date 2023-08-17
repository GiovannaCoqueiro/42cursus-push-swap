/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:41:46 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/17 11:45:26 by gcoqueir         ###   ########.fr       */
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
		return (SA);
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
		return (SB);
	}
	return (0);
}

int	swap_swap(t_stack *stack)
{
	if (stack->a_len >= 2 && stack->b_len >= 2)
	{
		swap_a(stack);
		swap_b(stack);
		return (SS);
	}
	return (0);
}
