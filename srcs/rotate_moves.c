/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:51:43 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/16 19:29:54 by gcoqueir         ###   ########.fr       */
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
		return (1);
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
		return (1);
	}
	return (0);
}

int	rol_rol(t_stack *stack)
{
	if (rol_a(stack) != 0 && rol_b(stack) != 0)
		return (1);
	return (0);
}
