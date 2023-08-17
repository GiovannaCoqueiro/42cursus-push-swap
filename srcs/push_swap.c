/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:56:55 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/17 17:32:20 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_a(t_stack *stack)
{
	size_t	i;

	i = -1;
	while (++i < stack->a_len)
		ft_printf("%d: %d\n", i, stack->a[i]);
}

void	print_b(t_stack *stack)
{
	size_t	i;

	i = -1;
	while (++i < stack->b_len)
		ft_printf("%d: %d\n", i, stack->b[i]);
}

void	test(t_stack *stack)
{
	push_b(stack);
	push_b(stack);
	push_b(stack);


	ft_printf("antes do swap b:\n");
	print_b(stack);
	swap_b(stack);
	ft_printf("após o swap b:\n");
	print_b(stack);
	ft_printf("antes do swap a:\n");
	print_a(stack);
	swap_a(stack);
	ft_printf("após o swap a:\n");
	print_a(stack);
	ft_printf("antes do swap swap:\n");
	ft_printf("a:\n");
	print_a(stack);
	ft_printf("b:\n");
	print_b(stack);
	swap_swap(stack);
	ft_printf("após do swap swap:\n");
	ft_printf("a:\n");
	print_a(stack);
	ft_printf("b:\n");
	print_b(stack);


	rol_a(stack);
	ft_printf("rotate a:\n");
	print_a(stack);
	rol_b(stack);
	ft_printf("rotate b:\n");
	print_b(stack);
	rol_rol(stack);
	ft_printf("rotate rotate:\n");
	ft_printf("a:\n");
	print_a(stack);
	ft_printf("b:\n");
	print_b(stack);


	revrol_a(stack);
	ft_printf("rev rotate a:\n");
	print_a(stack);
	revrol_b(stack);
	ft_printf("rev rotate b:\n");
	print_b(stack);
	revrol_revrol(stack);
	ft_printf("rev rotate rev rotate:\n");
	ft_printf("a:\n");
	print_a(stack);
	ft_printf("b:\n");
	print_b(stack);


	push_a(stack);
	ft_printf("push a:\n");
	print_a(stack);
	ft_printf("b:\n");
	print_b(stack);


	push_a(stack);
	push_a(stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_moves	moves;

	if (argc >= 2)
	{
		stack.moves = &moves;
		check_params(argc, argv);
		stack.a = create_stack(argc - 1, argv, &stack);
		stack.a_len = argc - 1;
		stack.b_len = 0;
		stack.copy = create_stack(argc - 1, argv, &stack);
		insertion_sort(stack.copy, argc - 1);
		put_index(stack.a, stack.copy, argc - 1);
		stack.b = malloc(sizeof(int) * argc - 1);
		if (stack.b == NULL)
			error_check(4, &stack);


		final_sort(&stack);
		print_a(&stack);
		ft_printf("%d\n", moves.len);
		size_t i = -1;
		while (++i < moves.len)
			ft_printf("%d\n", moves.moves[i]);
		// test(&stack);


		free_for_finish(&stack);
	}
	return (0);
}
