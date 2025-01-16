/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 03:02:38 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/07 17:47:29 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;
	size_t			i;

	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		t_dest[i] = t_src[i];
		i++;
	}
	return (dest);
}

/*
int main(void)
{
    char source[] = "Hello, World!";
    char destination[20];

    ft_memcpy(destination, source, 13);
    destination[13] = '\0';

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
*/
