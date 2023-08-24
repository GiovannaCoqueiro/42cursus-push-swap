/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:26:11 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/17 11:44:36 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_stack *stack)
{
	size_t	i;

	if (stack->b_len >= 1)
	{
		if (stack->a_len >= 1)
		{
			i = stack->a_len + 1;
			while (--i > 0)
				stack->a[i] = stack->a[i - 1];
		}
		stack->a_len++;
		stack->a[0] = stack->b[0];
		i = -1;
		while (++i < stack->b_len - 1)
			stack->b[i] = stack->b[i + 1];
		stack->b[i] = 0;
		stack->b_len--;
		return (PA);
	}
	return (0);
}

int	push_b(t_stack *stack)
{
	size_t	i;

	if (stack->a_len >= 1)
	{
		if (stack->b_len >= 1)
		{
			i = stack->b_len + 1;
			while (--i > 0)
				stack->b[i] = stack->b[i - 1];
		}
		stack->b_len++;
		stack->b[0] = stack->a[0];
		i = -1;
		while (++i < stack->a_len - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = 0;
		stack->a_len--;
		return (PB);
	}
	return (0);
}
