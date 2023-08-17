/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_call_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:41:57 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/17 11:28:41 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_number(char *str, size_t len);
static int	check_value(char *str);

void	check_params(int list, char **param)
{
	int		count;
	int		temp;
	size_t	len;

	count = 0;
	while (++count < list)
	{
		len = ft_strlen(param[count]);
		if (check_number(param[count], len) == 0)
			error_check(1, NULL);
		temp = count;
		while (--temp >= 1 && count > 1)
			if (ft_strcmp(param[count], param[temp]) == 0)
				error_check(2, NULL);
		if (check_value(param[count]) == 0)
			error_check(3, NULL);
	}
}

static int	check_number(char *str, size_t len)
{
	size_t	count;

	count = 0;
	if (str[count] == '-' || str[count] == '+')
	{
		if (len == 1)
			return (0);
		count++;
	}
	while (count < len)
		if (str[count] < '0' || str[count++] > '9')
			return (0);
	return (1);
}

static int	check_value(char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr > INTMAX || nbr < INTMIN)
		return (0);
	return (1);
}
