/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:53:36 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 17:47:11 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*t_s;

	i = 0;
	t_s = (unsigned char *)s;
	while (i < n)
	{
		t_s[i] = 0;
		i++;
	}
}
/*
int main(void)
{
    char buffer[10] = "Hello";

    printf("Antes de ft_bzero: %s\n", buffer);

    ft_bzero(buffer, 5);

    printf("Depois de ft_bzero:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", buffer[i]);
    }
    printf("\n");

    return 0;
}
*/