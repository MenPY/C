/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:24:16 by mesepoya          #+#    #+#             */
/*   Updated: 2021/01/24 20:24:36 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = -1;
	s1 = (char *)dest;
	s2 = (char *)src;
	while (++i < n)
		s1[i] = s2[i];
	return (dest);
}
