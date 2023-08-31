/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:18:12 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/31 07:05:27 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ddest;
	const char	*ssrc;
	size_t		i;

	ddest = (char *)dest;
	ssrc = (const char *)src;
	i = -1;
	while (++i < n)
		ddest[i] = ssrc[i];
	return (dest);
}
