/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:33:47 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/22 12:47:56 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		i;

	if (argc >= 2)
	{
		check_params(argc, argv);
		stack.stack_a = create_stack(argc, argv);
		stack.copy = create_stack(argc, argv);
		i = 0;
		while (++i < argc)
		{
			ft_printf("%p\n", &stack.stack_a->next);
			stack.stack_a = stack.stack_a->next;
		}
		i = 0;
		while (++i < argc)
		{
			ft_printf("%p\n", stack.stack_a);
			stack.stack_a = stack.stack_a->prev;
		}
	}
	return (0);
}
