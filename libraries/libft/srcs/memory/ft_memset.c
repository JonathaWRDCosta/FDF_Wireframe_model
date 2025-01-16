/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:00:35 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 18:25:23 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t_s;
	unsigned char	t_c;

	i = 0;
	t_s = (unsigned char *)s;
	t_c = (unsigned char)c;
	while (i < n)
	{
		t_s[i] = t_c;
		i++;
	}
	return (s);
}
/*
int main(void)
{
    char str[20] = "Hello, World!";
    
    ft_memset(str, 'X', 5);
    
    printf("Result: %s\n", str);

    return 0;
}
*/
