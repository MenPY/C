/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:31:49 by mesepoya          #+#    #+#             */
/*   Updated: 2021/01/24 20:31:50 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned long int i;
	unsigned long int j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
	{
		return ((char *)str);
	}
	while (str[i] != '\0' && i + ft_strlen(to_find) - 1 < len)
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
			{
				return ((char *)(str + i));
			}
			j++;
		}
		++i;
	}
	return (0);
}
