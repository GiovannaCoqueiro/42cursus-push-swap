/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:41:46 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/04 14:03:27 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *list, t_node *a, int i)
{
	int	temp;
	int	temp2;

	if (list->a_len >= 2)
	{
		temp = a->index;
		temp2 = a->value;
		a->index = a->next->index;
		a->value = a->next->value;
		a->next->index = temp;
		a->next->value = temp2;
		if (i == 1)
			ft_printf("sa\n");
	}
}

void	swap_b(t_list *list, t_node *b, int i)
{
	int	temp;
	int	temp2;

	if (list->a_len >= 2)
	{
		temp = b->index;
		temp2 = b->value;
		b->index = b->next->index;
		b->value = b->next->value;
		b->next->index = temp;
		b->next->value = temp2;
		if (i == 1)
			ft_printf("sb\n");
	}
}

void	swap_swap(t_list *list, int i)
{
	if (list->a_len >= 2 && list->b_len >= 2)
	{
		swap_a(list, list->a, 0);
		swap_b(list, list->b, 0);
		if (i == 1)
			ft_printf("ss\n");
	}
}
