/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:24:56 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/05 12:52:44 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc >= 2)
	{
		check_params(argc, argv);
		list = init_list(argc);
		list->a = create_list(list, argc, argv);
		get_index(argc, argv, list);
		take_instructions(list);
		free_for_finish(list);
	}
	return (0);
}
