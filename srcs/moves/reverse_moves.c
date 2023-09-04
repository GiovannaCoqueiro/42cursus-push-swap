/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 06:44:41 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/04 14:05:19 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrol_a(t_list *list, int i)
{
	t_node	*temp;

	temp = list->a;
	if (list->a_len >= 2)
	{
		while (list->a->next != temp)
			list->a = list->a->next;
		if (i == 1)
			ft_printf("rra\n");
	}
}

void	revrol_b(t_list *list, int i)
{
	t_node	*temp;

	temp = list->b;
	if (list->b_len >= 2)
	{
		while (list->b->next != temp)
			list->b = list->b->next;
		if (i == 1)
			ft_printf("rrb\n");
	}
}

void	revrol_revrol(t_list *list, int i)
{
	if (list->a_len >= 2 && list->b_len >= 2)
	{
		revrol_a(list, 0);
		revrol_b(list, 0);
		if (i == 1)
			ft_printf("rrr\n");
	}
}
