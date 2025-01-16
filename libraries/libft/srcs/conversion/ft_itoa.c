/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:03:01 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 18:00:45 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int				len;
	unsigned int	nb;

	len = 1;
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				intlen;
	char			*str;
	unsigned int	nb;

	intlen = ft_intlen(n);
	str = (char *)ft_calloc(intlen + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[intlen] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	else
	{
		nb = n;
	}
	while (intlen-- > 0 && str[intlen] != '-')
	{
		str[intlen] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
/*
int main(void)
{
    int test1 = 1234;
    int test2 = -5678;
    int test3 = 0;
    int test4 = -2147483648;
    int test5 = 2147483647;

    char *result1 = ft_itoa(test1);
    char *result2 = ft_itoa(test2);
    char *result3 = ft_itoa(test3);
    char *result4 = ft_itoa(test4);
    char *result5 = ft_itoa(test5);

    printf("Resultado 1: %s\n", result1);
    printf("Resultado 2: %s\n", result2);
    printf("Resultado 3: %s\n", result3);
    printf("Resultado 4: %s\n", result4);
    printf("Resultado 5: %s\n", result5);

    free(result1);
    free(result2);
    free(result3);
    free(result4);
    free(result5);

    return 0;
}
*/
