/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:43:32 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/04 08:53:07 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	t_node	*temp;

	temp = list->a;
	while (temp->next != list->a)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sorting(t_list *list)
{
	if (list->a_len == 2)
		swap_a(list, list->a, 0);
	else if (list->a_len == 3)
		while (is_sorted(list) == 0)
			sort_three(list, list->a);
	else
	{
		if (list->a_len >= 5)
			push_b(list, list->a, list->b);
		push_b(list, list->a, list->b);
		while (list->a_len > 3)
			fill_b(list);
		while (is_sorted(list) == 0)
			sort_three(list, list->a);
		prepare_push_a(list);
		while (list->b_len > 0)
			fill_a(list);
		put_zero_on_top(list);
	}
}

void	sort_three(t_list *list, t_node *node)
{
	t_node	*temp;

	temp = node;
	if (temp->index > temp->next->index && temp->next->index
		< temp->next->next->index && temp->index > temp->next->next->index)
		rol_a(list, 0);
	else if (temp->index > temp->next->index)
		swap_a(list, node, 0);
	else
		revrol_a(list, 0);
}
