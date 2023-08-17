/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 06:44:41 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/17 11:44:58 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	revrol_a(t_stack *stack)
{
	size_t	i;
	int		temp;

	if (stack->a_len >= 1)
	{
		temp = stack->a[stack->a_len - 1];
		i = stack->a_len;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[i] = temp;
		return (RRA);
	}
	return (0);
}

int	revrol_b(t_stack *stack)
{
	size_t	i;
	int		temp;

	if (stack->b_len >= 1)
	{
		temp = stack->b[stack->b_len - 1];
		i = stack->b_len;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[i] = temp;
		return (RRB);
	}
	return (0);
}

int	revrol_revrol(t_stack *stack)
{
	if (stack->a_len >= 1 && stack->b_len >= 1)
	{
		revrol_a(stack);
		revrol_b(stack);
		return (RRR);
	}
	return (0);
}
