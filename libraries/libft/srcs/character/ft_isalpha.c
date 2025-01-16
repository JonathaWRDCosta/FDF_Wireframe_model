/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:40:19 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 17:54:22 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
int main(void)
{
    char test1 = 'A';
    char test2 = 'z';
    char test3 = '5';
    char test4 = '%';
    char test5 = 'm';

    if (ft_isalpha(test1))
        printf("'%c' é uma letra.\n", test1);
    else
        printf("'%c' não é uma letra.\n", test1);

    if (ft_isalpha(test2))
        printf("'%c' é uma letra.\n", test2);
    else
        printf("'%c' não é uma letra.\n", test2);

    if (ft_isalpha(test3))
        printf("'%c' é uma letra.\n", test3);
    else
        printf("'%c' não é uma letra.\n", test3);

    if (ft_isalpha(test4))
        printf("'%c' é uma letra.\n", test4);
    else
        printf("'%c' não é uma letra.\n", test4);

    if (ft_isalpha(test5))
        printf("'%c' é uma letra.\n", test5);
    else
        printf("'%c' não é uma letra.\n", test5);

    return 0;
}
*/