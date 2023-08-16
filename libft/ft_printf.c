/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:46:05 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/12 08:46:23 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_variable(va_list list, char *str, int index);

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		print_count;
	int		index;

	if (str == NULL)
		return (-1);
	va_start(list, str);
	index = -1;
	print_count = 0;
	while (str[++index] != '\0')
	{
		if (str[index] == '%')
		{
			index++;
			while (str[index] != 'c' && str[index] != 's' && str[index] != 'p'
				&& str[index] != 'd' && str[index] != 'i' && str[index] != 'u'
				&& str[index] != 'x' && str[index] != 'X' && str[index] != '%')
				index++;
			print_count += convert_variable(list, (char *)str, index);
		}
		else
			print_count += print_char(str[index]);
	}
	va_end(list);
	return (print_count);
}

static int	convert_variable(va_list list, char *str, int index)
{
	int	count;

	count = 0;
	if (str[index] == 'c')
		count += print_char(va_arg(list, int));
	else if (str[index] == 's')
		count += print_str(va_arg(list, char *));
	else if (str[index] == 'p')
		count += print_ptr(va_arg(list, unsigned long), LOWER_HEX);
	else if (str[index] == 'd' || str[index] == 'i')
		count += print_nbr(va_arg(list, int), str, index, 1);
	else if (str[index] == 'u')
		count += print_unint(va_arg(list, unsigned int));
	else if (str[index] == 'x' || str[index] == 'X')
		count += print_hex(va_arg(list, unsigned int), str, index, 1);
	else if (str[index] == '%')
		count += print_char(str[index]);
	return (count);
}
