/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:08:12 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 18:05:52 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
int main(void)
{
    int test1 = 'A';
    int test2 = 127;
    int test3 = 128;
    int test4 = 'z';
    int test5 = -1;
    int test6 = ' ';
    int test7 = '\n';

    if (ft_isascii(test1))
        printf("'%c' (%d) é um caractere ASCII.\n", test1, test1);
    else
        printf("'%c' (%d) não é um caractere ASCII.\n", test1, test1);

    if (ft_isascii(test2))
        printf("'%d' é um caractere ASCII.\n", test2);
    else
        printf("'%d' não é um caractere ASCII.\n", test2);

    if (ft_isascii(test3))
        printf("'%d' é um caractere ASCII.\n", test3);
    else
        printf("'%d' não é um caractere ASCII.\n", test3);

    if (ft_isascii(test4))
        printf("'%c' (%d) é um caractere ASCII.\n", test4, test4);
    else
        printf("'%c' (%d) não é um caractere ASCII.\n", test4, test4);

    if (ft_isascii(test5))
        printf("'%d' não é um caractere ASCII.\n", test5);
    else
        printf("'%d' não é um caractere ASCII.\n", test5);

    if (ft_isascii(test6))
        printf("' ' (%d) é um caractere ASCII.\n", test6);
    else
        printf("' ' (%d) não é um caractere ASCII.\n", test6);

    if (ft_isascii(test7))
        printf("'\\n' (%d) é um caractere ASCII.\n", test7);
    else
        printf("'\\n' (%d) não é um caractere ASCII.\n", test7);

    return 0;
}
*/
