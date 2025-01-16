/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:15:41 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 23:28:23 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			j *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * j);
}
/*
int main(void)
{
    const char *str1 = "12345";
    printf("Input: \"%s\" | ft_atoi: %d\n", str1, ft_atoi(str1));

    const char *str2 = "-54321";
    printf("Input: \"%s\" | ft_atoi: %d\n", str2, ft_atoi(str2));

    const char *str3 = "   987";
    printf("Input: \"%s\" | ft_atoi: %d\n", str3, ft_atoi(str3));

    const char *str4 = "abc123";
    printf("Input: \"%s\" | ft_atoi: %d\n", str4, ft_atoi(str4));

    const char *str5 = "+42";
    printf("Input: \"%s\" | ft_atoi: %d\n", str5, ft_atoi(str5));

    const char *str6 = "0";
    printf("Input: \"%s\" | ft_atoi: %d\n", str6, ft_atoi(str6));

    return 0;
}
*/