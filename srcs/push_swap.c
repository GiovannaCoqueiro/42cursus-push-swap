/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:33:47 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/24 08:41:12 by gcoqueir         ###   ########.fr       */
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
		ft_printf("original list: %d\n", temp->value);
		temp = temp->next;
	}
	rol_a(list, list->a);
	temp = list->a;
	i = -1;
	while (++i < list->a_len)
	{
		ft_printf("rotate list: %d\n", temp->value);
		temp = temp->next;
	}
	revrol_a(list, list->a);
	temp = list->a;
	i = -1;
	while (++i < list->a_len)
	{
		ft_printf("rev rotate list: %d\n", temp->value);
		temp = temp->next;
	}
	swap_a(list, list->a);
	temp = list->a;
	i = -1;
	while (++i < list->a_len)
	{
		ft_printf("swap list: %d\n", temp->value);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*list;
	// t_node	*temp;

	if (argc >= 2)
	{
		check_params(argc, argv);
		list = init_list();
		list->a = create_list(list, argc, argv);

		test(list);
		// int i = -1;
		// while (++i < list.a_len)
		// {
		// 	ft_printf("%d\n", i);
		// 	ft_printf("%d\n", temp->value);
		// 	temp = temp->next;
		// }
		free_for_finish(list);
	}
	return (0);
}
