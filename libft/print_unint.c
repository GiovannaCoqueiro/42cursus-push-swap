/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:50:26 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/12 08:50:33 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unint(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
		count += print_unint(nbr / 10);
	count += print_char((nbr % 10) + '0');
	return (count);
}
