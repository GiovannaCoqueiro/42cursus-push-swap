/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:51:43 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/31 13:20:32 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rol_a(t_list *list, int i)
{
	if (list->a_len >= 2)
	{
		list->a = list->a->next;
		if (i == 0)
			ft_printf("ra\n");
		return (RA);
	}
	return (0);
}

int	rol_b(t_list *list, int i)
{
	if (list->b_len >= 2)
	{
		list->b = list->b->next;
		if (i == 0)
			ft_printf("rb\n");
		return (RB);
	}
	return (0);
}

int	rol_rol(t_list *list)
{
	if (list->a_len >= 2 && list->b_len >= 2)
	{
		rol_a(list, 1);
		rol_b(list, 1);
		ft_printf("rr\n");
		return (RR);
	}
	return (0);
}
