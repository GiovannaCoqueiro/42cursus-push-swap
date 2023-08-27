/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:43:32 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/26 16:40:42 by gcoqueir         ###   ########.fr       */
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
		swap_a(list, list->a);
	else if (list->a_len == 3)
		while (is_sorted(list) == 0)
			sort_three(list, list->a);
	else
		if (list->a_len >= 5)
			push_b(list, list->a, list->b);
		push_b(list, list->a, list->b);
		while (list->a_len > 3)
			fill_b(list, list->a, list->b);
		while (is_sorted(list) == 0)
			sort_three(list, list->a);
		while (list->b_len > 0)
			fill_a(list, list->a, list->b);
}

void	sort_three(t_list *list, t_node *node)
{
	t_node	*temp;

	temp = node;
	if (temp->index > temp->next->index && temp->next->index
		< temp->next->next->index && temp->index > temp->next->next->index)
		rol_a(list, node);
	else if (temp->index > temp->next->index)
		swap_a(list, node);
	else
		revrol_a(list, node);
}

void	fill_b(t_list *list, t_node *a, t_node *b)
{

}

void	fill_a(t_list *list, t_node *a, t_node *b)
{

}
