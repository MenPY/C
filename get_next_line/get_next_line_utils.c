/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:58:07 by atarverd          #+#    #+#             */
/*   Updated: 2021/05/04 13:58:10 by atarverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *string, char *buff)
{
	char	*result;
	int		i;
	int		j;

	if (!(result = malloc(sizeof(char)
	* (ft_strlen(string) + ft_strlen(buff) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (string)
		while (string[i] != '\0')
			result[j++] = string[i++];
	i = 0;
	if (buff)
		while (buff[i] != '\0')
			result[j++] = buff[i++];
	result[j] = '\0';
	free(string);
	return (result);
}

char	*cut_next_line(char *stored)
{
	int		i;
	int		j;
	char	*array;

	i = 0;
	j = 0;
	if (!stored)
		return (NULL);
	while (stored[i] && stored[i] != '\n')
		i++;
	if (!stored[i])
	{
		free(stored);
		return (NULL);
	}
	if (!(array = malloc(sizeof(char) * (ft_strlen(stored) - i + 1))))
		return (NULL);
	i++;
	while (stored[i])
		array[j++] = stored[i++];
	array[j] = '\0';
	free(stored);
	return (array);
}

char	*add_line(char *stored)
{
	int		i;
	char	*array;

	i = 0;
	while (stored && stored[i] != '\0' && stored[i] != '\n')
		i++;
	if (!(array = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (stored && stored[i] != '\0' && stored[i] != '\n')
	{
		array[i] = stored[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		is_next_line(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
