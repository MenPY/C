/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:03:11 by mesepoya          #+#    #+#             */
/*   Updated: 2021/01/30 15:03:14 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned		int	i;
	const unsigned char *s1;
	const unsigned char *s2;

	s1 = (const unsigned char *)arr1;
	s2 = (const unsigned char *)arr2;
	i = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (n)
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
