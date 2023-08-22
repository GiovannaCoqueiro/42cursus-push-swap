/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:25:10 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/22 12:43:52 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_stack(int range, char **param)
{
	int		i;
	t_node	*a;
	t_node	*temp;
	t_node	*prev_temp;

	a = new_node(ft_atol(param[1]));
	temp = a;
	a->next = temp;
	prev_temp = a;
	i = 1;
	while (++i < range)
	{
		temp->next = new_node(ft_atol(param[i]));
		temp->prev = prev_temp;
		prev_temp = temp;
		temp = temp->next;
		temp->next = a;
	}
	a->prev = temp;
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

void	insertion_sort(int *tab, int range)
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

void	put_index(int *tab, int *copy, int range)
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
