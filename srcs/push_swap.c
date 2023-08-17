/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:56:55 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/17 08:25:34 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insertion_sort(int *tab, int range);
static void	put_index(int *tab, int *copy, int range);

void	test(t_stack *stack)
{
	size_t	i;

	i = -1;
	ft_printf("push b:\n");
	push_b(stack);
	push_b(stack);
	push_b(stack);
	ft_printf("antes do swap b:\n");
	while (++i < stack->b_len)
		ft_printf("%d: %d\n", i, stack->b[i]);


	swap_b(stack);
	ft_printf("após o swap b:\n");
	i = -1;
	while (++i < stack->b_len)
		ft_printf("%d: %d\n", i, stack->b[i]);
	ft_printf("antes do swap a:\n");
	i = -1;
	while (++i < stack->a_len)
		ft_printf("%d: %d\n", i, stack->a[i]);
	swap_a(stack);
	ft_printf("após o swap a:\n");
	i = -1;
	while (++i < stack->a_len)
		ft_printf("%d: %d\n", i, stack->a[i]);
	ft_printf("antes do swap swap:\n");
	ft_printf("a\n");
	i = -1;
	while (++i < stack->a_len)
		ft_printf("%d: %d\n", i, stack->a[i]);
	ft_printf("b:\n");
	i = -1;
	while (++i < stack->b_len)
		ft_printf("%d: %d\n", i, stack->b[i]);
	swap_swap(stack);
	ft_printf("após do swap swap:\n");
	ft_printf("a\n");
	i = -1;
	while (++i < stack->a_len)
		ft_printf("%d: %d\n", i, stack->a[i]);
	ft_printf("b:\n");
	i = -1;
	while (++i < stack->b_len)
		ft_printf("%d: %d\n", i, stack->b[i]);


	rol_a(stack);
	ft_printf("rotate a:\n");
	i = -1;
	while (++i < stack->a_len)
		ft_printf("%d: %d\n", i, stack->a[i]);
	rol_b(stack);
	i = -1;
	ft_printf("rotate b:\n");
	while (++i < stack->b_len)
		ft_printf("%d: %d\n", i, stack->b[i]);
	rol_rol(stack);
	ft_printf("rotate rotate:\n");
	ft_printf("a:\n");
	i = -1;
	while (++i < stack->a_len)
		ft_printf("%d: %d\n", i, stack->a[i]);
	ft_printf("b:\n");
	i = -1;
	while (++i < stack->b_len)
		ft_printf("%d: %d\n", i, stack->b[i]);


	revrol_a(stack);
	ft_printf("rev rotate a:\n");
	i = -1;
	while (++i < stack->a_len)
		ft_printf("%d: %d\n", i, stack->a[i]);
	revrol_b(stack);
	i = -1;
	ft_printf("rev rotate b:\n");
	while (++i < stack->b_len)
		ft_printf("%d: %d\n", i, stack->b[i]);
	revrol_revrol(stack);
	ft_printf("rev rotate rev rotate:\n");
	ft_printf("a:\n");
	i = -1;
	while (++i < stack->a_len)
		ft_printf("%d: %d\n", i, stack->a[i]);
	ft_printf("b:\n");
	i = -1;
	while (++i < stack->b_len)
		ft_printf("%d: %d\n", i, stack->b[i]);


	push_a(stack);
	ft_printf("push a:\n");
	i = -1;
	while (++i < stack->a_len)
		ft_printf("%d: %d\n", i, stack->a[i]);
	ft_printf("b:\n");
	i = -1;
	while (++i < stack->b_len)
		ft_printf("%d: %d\n", i, stack->b[i]);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc >= 2)
	{
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


		test(&stack);


		free_for_finish(&stack);
	}
	return (0);
}

int	*create_stack(int range, char **param, t_stack *stack)
{
	int	index;
	int	*tab;

	tab = malloc(sizeof(int) * range);
	if (tab == NULL)
		error_check(4, stack);
	index = -1;
	while (++index < range)
		tab[index] = ft_atol(param[index + 1]);
	return (tab);
}

static void	insertion_sort(int *tab, int range)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (++i < range)
	{
		j = i;
		while (j > 0 && tab[j] < tab[j - 1])
		{
			temp = tab[j];
			tab[j] = tab[j - 1];
			tab[j - 1] = temp;
			j--;
		}
	}
}

static void	put_index(int *tab, int *copy, int range)
{
	int	i;
	int	j;

	i = -1;
	while (++i < range)
	{
		j = 0;
		while (tab[i] != copy[j])
			j++;
		tab[i] = j;
	}
}
