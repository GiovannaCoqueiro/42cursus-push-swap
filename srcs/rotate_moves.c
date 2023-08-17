/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:51:43 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/17 11:45:10 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rol_a(t_stack *stack)
{
	size_t	i;
	int		temp;

	if (stack->a_len >= 1)
	{
		temp = stack->a[0];
		i = -1;
		while (++i < stack->a_len - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = temp;
		return (RA);
	}
	return (0);
}

int	rol_b(t_stack *stack)
{
	size_t	i;
	int		temp;

	if (stack->b_len >= 1)
	{
		temp = stack->b[0];
		i = -1;
		while (++i < stack->b_len - 1)
			stack->b[i] = stack->b[i + 1];
		stack->b[i] = temp;
		return (RB);
	}
	return (0);
}

int	rol_rol(t_stack *stack)
{
	if (stack->a_len >= 0 && stack->b_len >= 1)
	{
		rol_a(stack);
		rol_b(stack);
		return (RR);
	}
	return (0);
}
