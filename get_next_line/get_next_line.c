/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:57:46 by atarverd          #+#    #+#             */
/*   Updated: 2021/05/04 13:57:51 by atarverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	int			size;
	char		*buff;
	static char	*stored;

	size = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[size] = '\0';
		stored = ft_strjoin(stored, buff);
		if (is_next_line(stored))
			break ;
	}
	free(buff);
	if (size < 0)
		return (-1);
	*line = add_line(stored);
	stored = cut_next_line(stored);
	if (size == 0 && !stored)
		return (0);
	return (1);
}
