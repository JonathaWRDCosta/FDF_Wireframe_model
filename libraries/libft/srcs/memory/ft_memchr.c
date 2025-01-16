/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:14:25 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 18:21:01 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t_s;
	unsigned char	t_c;

	i = 0;
	t_s = (unsigned char *)s;
	t_c = (unsigned char)c;
	while (i < n)
	{
		if (t_s[i] == t_c)
			return (t_s + i);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    char str[] = "Hello, World!";
    char ch = 'W';
    size_t n = 13;
    
    char *result = ft_memchr(str, ch, n);
    
    if (result != NULL)
        printf("Found '%c' at position: %ld\n", *result, result - str);
    else
        printf("Character '%c' not found\n", ch);

    return 0;
}

*/