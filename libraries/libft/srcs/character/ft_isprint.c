/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:09:50 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 17:59:15 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int main(void)
{
    int test1 = 'A';
    int test2 = 31;
    int test3 = 32;
    int test4 = 126;
    int test5 = 127;

    if (ft_isprint(test1))
        printf("'%c' (%d) é imprimível.\n", test1, test1);
    else
        printf("'%c' (%d) não é imprimível.\n", test1, test1);

    if (ft_isprint(test2))
        printf("%d é imprimível.\n", test2);
    else
        printf("%d não é imprimível.\n", test2);

    if (ft_isprint(test3))
        printf("%d é imprimível.\n", test3);
    else
        printf("%d não é imprimível.\n", test3);

    if (ft_isprint(test4))
        printf("%d é imprimível.\n", test4);
    else
        printf("%d não é imprimível.\n", test4);

    if (ft_isprint(test5))
        printf("%d é imprimível.\n", test5);
    else
        printf("%d não é imprimível.\n", test5);

    return 0;
}

*/