/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:33:47 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/04 08:17:20 by gcoqueir         ###   ########.fr       */
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
		if (is_sorted(list) == 0)
			sorting(list);
		free_for_finish(list);
	}
	return (0);
}
