/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:29:29 by abourin           #+#    #+#             */
/*   Updated: 2019/10/31 15:03:05 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int t;
	char c;

	c = 'a';
	t = 50;
	printf("%d\n", -589);
    printf("%-4d\n", -2464);
    printf("%.5d\n", -2372);
	printf("%p\n", NULL);
	printf("%15p\n", NULL);
	printf("%-15p\n", NULL);
    printf("ret = %d\n", printf("%%p::[%010d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%10d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%.5d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%01.1d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%010.1d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%01.50d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%1.50d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%0100.50d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%010d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%10d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%.5d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%01.1d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%010.1d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%01.50d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%1.50d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%0100.50d]\n", 8473));
	printf("%c\n", 'a');
	printf("%10c\n", 't');
	printf("%1c\n", 'y');
	printf("%50.2s\n", "Coucou");
	printf("%50.2s\n", NULL);
	printf("%5.0s\n", "Hello");
	printf("%.1s\n", "Test");
	printf("%10s\n", NULL);
	printf("%10s\n", "Ok");

    }
