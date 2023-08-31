/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:25:10 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/31 14:33:46 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*new_node(long nbr);

t_list	*init_list(int range)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		error_check(NULL);
	list->a = NULL;
	list->a_len = 0;
	list->b = NULL;
	list->b_len = 0;
	list->b_max = 0;
	list->b_min = range;
	return (list);
}

t_node	*create_list(t_list *list, int range, char **param)
{
	t_node	*node;
	t_node	*temp;
	int		i;

	node = new_node(ft_atol(param[1]));
	list->a_len++;
	temp = node;
	i = 1;
	while (++i < range)
	{
		temp->next = new_node(ft_atol(param[i]));
		list->a_len++;
		temp = temp->next;
	}
	list->total_len = list->a_len;
	temp->next = node;
	return (node);
}

static t_node	*new_node(long nbr)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = nbr;
	node->next = NULL;
	return (node);
}
