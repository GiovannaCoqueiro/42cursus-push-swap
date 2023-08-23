/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:25:10 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/22 19:27:03 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_stack(int range, char **param)
{
	int		i;
	t_node	*a;
	t_node	*temp;

	a = new_node(ft_atol(param[1]));
	a->len = range - 1;
	temp = a;
	a->next = temp;
	i = 1;
	while (++i < range)
	{
		temp->next = new_node(ft_atol(param[i]));
		temp->next->prev = temp;
		temp = temp->next;
	}
	a->prev = temp;
	temp->next = a;
	return (a);
}

t_node	*new_node(long nbr)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = nbr;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// void	get_index(t_node *node, int range)
// {

// }

// void	put_index(t_node *a, t_node *copy, int range)
// {

// }
