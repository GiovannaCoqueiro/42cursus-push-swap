/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:49:30 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/12 08:49:37 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_hexlong(unsigned long nbr, char *base);

int	print_ptr(unsigned long nbr, char *base)
{
	int	count;

	if (nbr == 0)
		return (print_str("(nil)"));
	count = 0;
	count += print_str("0x");
	count += print_hexlong(nbr, base);
	return (count);
}

static int	print_hexlong(unsigned long nbr, char *base)
{
	int				count;

	count = 0;
	if (nbr > 15)
		count += print_hexlong(nbr / 16, base);
	count += print_char(base[nbr % 16]);
	return (count);
}
