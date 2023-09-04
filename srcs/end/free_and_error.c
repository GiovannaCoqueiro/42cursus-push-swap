/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:26:37 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/04 15:50:55 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_for_finish(t_list *list)
{
	if (list->a != NULL)
		free_node(&list->a, list->a_len);
	if (list->b != NULL)
		free_node(&list->b, list->b_len);
	if (list->cmd != NULL)
		free(list->cmd);
	free(list);
}

void	free_node(t_node **node, int len)
{
	int		i;
	t_node	*temp;

	i = -1;
	while (++i < len)
	{
		temp = *node;
		*node = temp->next;
		free(temp);
	}
}

void	error_check(t_list *list)
{
	if (list != NULL)
		free_for_finish(list);
	ft_putendl_fd("Error", 2);
	exit (1);
}
