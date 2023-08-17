/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:25:10 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/17 11:26:00 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_stack(int range, char **param, t_stack *stack)
{
	int	index;
	int	*tab;

	tab = malloc(sizeof(int) * range);
	if (tab == NULL)
		error_check(4, stack);
	index = -1;
	while (++index < range)
		tab[index] = ft_atol(param[index + 1]);
	return (tab);
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
