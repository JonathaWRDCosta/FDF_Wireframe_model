/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:03:15 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 12:42:19 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
int main(void)
{
    int test1 = '5';
    int test2 = 'A';
    int test3 = '0';
    int test4 = '9';
    int test5 = 10;
    int test6 = 57;
    int test7 = 48;

    if (ft_isdigit(test1))
        printf("'%c' (%d) é um dígito.\n", test1, test1);
    else
        printf("'%c' (%d) não é um dígito.\n", test1, test1);

    if (ft_isdigit(test2))
        printf("'%c' (%d) é um dígito.\n", test2, test2);
    else
        printf("'%c' (%d) não é um dígito.\n", test2, test2);

    if (ft_isdigit(test3))
        printf("'%c' (%d) é um dígito.\n", test3, test3);
    else
        printf("'%c' (%d) não é um dígito.\n", test3, test3);

    if (ft_isdigit(test4))
        printf("'%c' (%d) é um dígito.\n", test4, test4);
    else
        printf("'%c' (%d) não é um dígito.\n", test4, test4);

    if (ft_isdigit(test5))
        printf("%d é um dígito.\n", test5);
    else
        printf("%d não é um dígito.\n", test5);

    if (ft_isdigit(test6))
        printf("%d é um dígito.\n", test6);
    else
        printf("%d não é um dígito.\n", test6);

    if (ft_isdigit(test7))
        printf("%d é um dígito.\n", test7);
    else
        printf("%d não é um dígito.\n", test7);

    return 0;
}

*/