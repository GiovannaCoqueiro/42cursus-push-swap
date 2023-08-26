/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:33:47 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/26 16:41:25 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_list *list)
{
	int		i;
	t_node	*temp;

	temp = list->a;
	i = -1;
	while (++i < list->a_len)
	{
		ft_printf("original list: %d\n", temp->index);
		temp = temp->next;
	}


	ft_printf("\n\n");
	push_b(list, list->a, list->b);
	push_b(list, list->a, list->b);
	push_b(list, list->a, list->b);
	temp = list->a;
	i = -1;
	while (++i < list->a_len)
	{
		ft_printf("push b list a: %d\n", temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
	temp = list->b;
	i = -1;
	while (++i < list->b_len)
	{
		ft_printf("push b list b: %d\n", temp->index);
		temp = temp->next;
	}


	ft_printf("\n\n");
	rol_a(list, list->a);
	temp = list->a;
	i = -1;
	while (++i < list->a_len)
	{
		ft_printf("rotate list a: %d\n", temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
	rol_b(list, list->b);
	temp = list->b;
	i = -1;
	while (++i < list->b_len)
	{
		ft_printf("rotate list b: %d\n", temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
	rol_rol(list);
	temp = list->a;
	i = -1;
	while (++i < list->a_len)
	{
		ft_printf("rotate rotate list a: %d\n", temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
	temp = list->b;
	i = -1;
	while (++i < list->b_len)
	{
		ft_printf("rotate rotate list b: %d\n", temp->index);
		temp = temp->next;
	}


	ft_printf("\n\n");
	revrol_a(list, list->a);
	temp = list->a;
	i = -1;
	while (++i < list->a_len)
	{
		ft_printf("rev rotate list a: %d\n", temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
	revrol_b(list, list->b);
	temp = list->b;
	i = -1;
	while (++i < list->b_len)
	{
		ft_printf("rev rotate list b: %d\n", temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
	revrol_revrol(list);
	temp = list->a;
	i = -1;
	while (++i < list->a_len)
	{
		ft_printf("rev rev rotate list a: %d\n", temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
	temp = list->b;
	i = -1;
	while (++i < list->b_len)
	{
		ft_printf("rev rev rotate list b: %d\n", temp->index);
		temp = temp->next;
	}


	ft_printf("\n\n");
	swap_a(list, list->a);
	temp = list->a;
	i = -1;
	while (++i < list->a_len)
	{
		ft_printf("swap list a: %d\n", temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
	swap_b(list, list->b);
	temp = list->b;
	i = -1;
	while (++i < list->b_len)
	{
		ft_printf("swap list b: %d\n", temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
	swap_swap(list);
	temp = list->a;
	i = -1;
	while (++i < list->a_len)
	{
		ft_printf("swap swap list a: %d\n", temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
	temp = list->b;
	i = -1;
	while (++i < list->b_len)
	{
		ft_printf("swap swap list b: %d\n", temp->index);
		temp = temp->next;
	}


	ft_printf("\n\n");
	push_a(list, list->a, list->b);
	temp = list->a;
	i = -1;
	while (++i < list->a_len)
	{
		ft_printf("push a list a: %d\n", temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
	temp = list->b;
	i = -1;
	while (++i < list->b_len)
	{
		ft_printf("push a list b: %d\n", temp->index);
		temp = temp->next;
	}
	push_a(list, list->a, list->b);
	push_a(list, list->a, list->b);
}

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc >= 2)
	{
		check_params(argc, argv);
		list = init_list();
		list->a = create_list(list, argc, argv);
		get_index(argc, argv, list);
		// test(list);
		if (is_sorted(list) == 0)
			sorting(list);
		free_for_finish(list);
	}
	return (0);
}
