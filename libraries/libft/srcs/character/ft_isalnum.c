/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:05:12 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 18:13:41 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
int	main(void)
{
    test1 = 'A';
    test2 = '1';
    test3 = '@';
    test4 = 'z';
    test5 = ' ';
    if (ft_isalnum(test1))
        printf("'%c' é alfanumérico.\n", test1);
    else
        printf("'%c' não é alfanumérico.\n", test1);
    if (ft_isalnum(test2))
        printf("'%c' é alfanumérico.\n", test2);
    else
        printf("'%c' não é alfanumérico.\n", test2);
    if (ft_isalnum(test3))
        printf("'%c' é alfanumérico.\n", test3);
    else
        printf("'%c' não é alfanumérico.\n", test3);
    if (ft_isalnum(test4))
        printf("'%c' é alfanumérico.\n", test4);
    else
        printf("'%c' não é alfanumérico.\n", test4);
    if (ft_isalnum(test5))
        printf("'%c' é alfanumérico.\n", test5);
    else
        printf("'%c' não é alfanumérico.\n", test5);
    return (0);
}
*/
