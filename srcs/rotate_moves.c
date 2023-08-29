/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:51:43 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/29 09:42:06 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rol_a(t_list *list)
{
	if (list->a_len >= 2)
	{
		list->a = list->a->next;
		return (RA);
	}
	return (0);
}

int	rol_b(t_list *list)
{
	if (list->b_len >= 2)
	{
		list->b = list->b->next;
		return (RB);
	}
	return (0);
}

int	rol_rol(t_list *list)
{
	if (list->a_len >= 2 && list->b_len >= 2)
	{
		rol_a(list);
		rol_b(list);
		return (RR);
	}
	return (0);
}
