/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:51:01 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/05 12:52:36 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_move(t_list *list, char *line);

void	take_instructions(t_list *list)
{
	while (1)
	{
		list->cmd = get_line(0);
		if (list->cmd == NULL)
			break ;
		exec_move(list, list->cmd);
		free(list->cmd);
	}
	if (is_sorted(list) == 1 && list->b_len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static void	exec_move(t_list *list, char *line)
{
	if (ft_strcmp(line, SA) == 0)
		swap_a(list, list->a, 0);
	else if (ft_strcmp(line, SB) == 0)
		swap_b(list, list->b, 0);
	else if (ft_strcmp(line, SS) == 0)
		swap_swap(list, 0);
	else if (ft_strcmp(line, PA) == 0)
		push_a(list, list->a, list->b, 0);
	else if (ft_strcmp(line, PB) == 0)
		push_b(list, list->a, list->b, 0);
	else if (ft_strcmp(line, RA) == 0)
		rol_a(list, 0);
	else if (ft_strcmp(line, RB) == 0)
		rol_b(list, 0);
	else if (ft_strcmp(line, RR) == 0)
		rol_rol(list, 0);
	else if (ft_strcmp(line, RRA) == 0)
		revrol_a(list, 0);
	else if (ft_strcmp(line, RRB) == 0)
		revrol_b(list, 0);
	else if (ft_strcmp(line, RRR) == 0)
		revrol_revrol(list, 0);
	else
		error_check(list);
}
