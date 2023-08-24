/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:25:10 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/24 15:43:22 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		error_check(4, NULL);
	list->a = NULL;
	list->a_len = 0;
	list->b = NULL;
	list->b_len = 0;
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
	temp->next = node;
	return (node);
}

t_node	*new_node(long nbr)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = nbr;
	node->next = NULL;
	return (node);
}

// void	get_index(t_node *node, int range)
// {

// }

// void	put_index(t_node *a, t_node *copy, int range)
// {

// }
