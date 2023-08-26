/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:11:06 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/26 14:14:46 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insertion_sort(int *tab, int range);
static void	put_index(t_list *list, int	*copy, int range);

void	get_index(int range, char **param, t_list *list)
{
	int		*copy;
	int		i;

	copy = malloc(sizeof(int) * range - 1);
	if (copy == NULL)
		error_check(4, list);
	i = -1;
	while (++i < range - 1)
		copy[i] = ft_atol(param[i + 1]);
	insertion_sort(copy, range - 1);
	put_index(list, copy, range);
	free(copy);
}

static void	put_index(t_list *list, int	*copy, int range)
{
	int		i;
	int		checker;
	t_node	*temp;

	i = -1;
	while (++i < range - 1)
	{
		temp = list->a;
		checker = 0;
		while (temp != list->a || checker == 0)
		{
			if (temp->value == copy[i])
			{
				temp->index = i;
				break ;
			}
			temp = temp->next;
			checker = 1;
		}
	}
}

static void	insertion_sort(int *tab, int range)
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
