/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:29:44 by mesepoya          #+#    #+#             */
/*   Updated: 2021/01/24 20:29:45 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*string;

	if (c == '\0')
		return (char *)str + ft_strlen(str);
	i = -1;
	string = (char *)str;
	while (string[++i] != '\0')
		if (string[i] == (char)c)
			return (&string[i]);
	return (NULL);
}
