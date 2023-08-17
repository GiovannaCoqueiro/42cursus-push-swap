/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:17:52 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/17 17:33:48 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	next_moves(t_stack *stack, t_moves *moves)
{
	if (stack->a_len == 2)
	{
		moves->moves = malloc(sizeof(int) * 1);
		moves->len++;
		moves->moves[++moves->index] = swap_a(stack);
	}
	else if (stack->a_len == 3 && is_sorted(stack) == 0)
		just_three(stack, moves);
	// else if (stack->b_len == 0)
	// {
	// 	push_b(stack);
	// 	push_b(stack);
	// }
}

void	just_three(t_stack *stack, t_moves *moves)
{
	moves->moves = alloc_moves(moves, 1);
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
		&& stack->a[0] > stack->a[2])
		moves->moves[++moves->index] = rol_a(stack);
	else if (stack->a[0] > stack->a[1])
		moves->moves[++moves->index] = swap_a(stack);
	else
		moves->moves[++moves->index] = revrol_a(stack);
}

int	*alloc_moves(t_moves *moves, int len)
{
	int	*temp;

	moves->len += len;
	if (moves->moves != NULL)
	{
		ft_printf("%p\n", moves->moves);
		temp = malloc(sizeof(int) * moves->len);
		if (temp == NULL)
			return (NULL);
		ft_memcpy(temp, moves->moves, moves->len - len);
		free(moves->moves);
	}
	else
	{
		temp = malloc(sizeof(int) * moves->len);
		if (temp == NULL)
			return (NULL);
	}
	return (temp);
}
