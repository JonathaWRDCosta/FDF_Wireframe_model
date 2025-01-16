/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:30:48 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/07 17:49:05 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;

	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, len));
	while (len--)
	{
		t_dest[len] = t_src[len];
	}
	return (dest);
}
/*
int main(void)
{
    char str[] = "Hello, World!";
    
    ft_memmove(str + 7, str, 6);
    
    printf("Result: %s\n", str);
		
    return 0;
}
*/
