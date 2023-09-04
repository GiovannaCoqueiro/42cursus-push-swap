/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:07:52 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/09/04 17:27:44 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_and_return(char *str);

char	*get_line(int fd)
{
	char	*temp;
	char	*str;
	int		bytes_read;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	str = "\0";
	bytes_read = 1;
	while (ft_strchr(str, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_and_return(temp));
		temp[bytes_read] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	if (ft_strcmp("\0", str) == 0)
		return (free_and_return(str));
	return (str);
}

static void	*free_and_return(char *str)
{
	free(str);
	return (NULL);
}
