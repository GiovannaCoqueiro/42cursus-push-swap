/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:51:43 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/24 07:57:26 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rol_a(t_list *list, t_node *a)
{
	if (list->a_len >= 2)
	{
		list->a = a->next;
		return (RA);
	}
	return (0);
}

int	rol_b(t_list *list, t_node *b)
{
	if (list->b_len >= 2)
	{
		list->b = b->next;
		return (RB);
	}
	return (0);
}

int	rol_rol(t_list *list)
{
	if (list->a_len >= 2 && list->b_len >= 2)
	{
		rol_a(list, list->a);
		rol_b(list, list->b);
		return (RR);
	}
	return (0);
}
