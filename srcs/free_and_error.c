/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:26:37 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/22 13:20:47 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_for_finish(t_stack *stack)
{
	if (stack->a != NULL)
		free(stack->a);
	if (stack->b != NULL)
		free(stack->b);
	if (stack->copy != NULL)
		free(stack->copy);
	if (stack->moves->moves != NULL)
		free(stack->moves->moves);
}

void	error_check(int i, t_stack *stack)
{
	if (stack != NULL)
		free_for_finish(stack);
	ft_printf("Error\n");
	exit (i);
}
