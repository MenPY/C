/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:21:09 by mesepoya          #+#    #+#             */
/*   Updated: 2021/01/24 20:21:12 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)dest;
	s2 = (char *)src;
	while (i < n)
	{
		if (s2[i] != c)
		{
			s1[i] = s2[i];
			i++;
		}
		else
		{
			s1[i] = s2[i];
			return (&dest[i] + 1);
		}
	}
	return (NULL);
}
