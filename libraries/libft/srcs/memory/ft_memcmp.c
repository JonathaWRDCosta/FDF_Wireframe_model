/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:46:50 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 18:22:21 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t_s1;
	unsigned char	*t_s2;
	size_t			i;

	if (n == 0)
		return (0);
	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (t_s1[i] != t_s2[i])
			return (t_s1[i] - t_s2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
    char str1[] = "Hello";
    char str2[] = "Hello, World!";
    size_t n = 5;

    int result = ft_memcmp(str1, str2, n);

    if (result == 0)
        printf("The first %zu bytes are equal.\n", n);
    else if (result < 0)
        printf("The first %zu bytes of str1 are less than str2.\n", n);
    else
        printf("The first %zu bytes of str1 are greater than str2.\n", n);

    return 0;
}

*/