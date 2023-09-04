/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:51:43 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/04 14:04:32 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rol_a(t_list *list, int i)
{
	if (list->a_len >= 2)
	{
		list->a = list->a->next;
		if (i == 1)
			ft_printf("ra\n");
	}
}

void	rol_b(t_list *list, int i)
{
	if (list->b_len >= 2)
	{
		list->b = list->b->next;
		if (i == 1)
			ft_printf("rb\n");
	}
}

void	rol_rol(t_list *list, int i)
{
	if (list->a_len >= 2 && list->b_len >= 2)
	{
		rol_a(list, 0);
		rol_b(list, 0);
		if (i == 1)
			ft_printf("rr\n");
	}
}
