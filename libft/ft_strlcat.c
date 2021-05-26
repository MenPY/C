/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:30:19 by mesepoya          #+#    #+#             */
/*   Updated: 2021/01/24 20:30:21 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int a;
	unsigned int b;
	unsigned int c;

	a = 0;
	while (dest[a] != '\0')
		++a;
	c = 0;
	while (src[c] != '\0')
		++c;
	if (size <= a)
		c += size;
	else
		c += a;
	b = 0;
	while (src[b] != '\0' && a + 1 < size)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (c);
}
