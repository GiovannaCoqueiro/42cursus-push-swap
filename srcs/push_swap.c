/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:33:47 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/22 13:35:53 by gcoqueir         ###   ########.fr       */
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
		stack.a = create_stack(argc, argv);
		stack.copy = create_stack(argc, argv);
		// insertion_sort(&stack.copy, argc - 1);
	}
	return (0);
}
