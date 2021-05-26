/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:57:57 by atarverd          #+#    #+#             */
/*   Updated: 2021/05/04 13:57:58 by atarverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*ft_strjoin(char *string, char *buff);
size_t	ft_strlen(const char *str);
int		get_next_line(int fd, char **line);
int		is_next_line(char *string);
char	*cut_next_line(char *stored);
char	*add_line(char *stored);
#endif
