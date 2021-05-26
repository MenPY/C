/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:02:45 by mesepoya          #+#    #+#             */
/*   Updated: 2021/01/30 15:02:48 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*new;
	unsigned char	c1;

	i = 0;
	new = (unsigned char *)arr;
	c1 = (unsigned char)c;
	while (n--)
	{
		if (new[i] == c1)
			return (new + i);
		++i;
	}
	return (NULL);
}
