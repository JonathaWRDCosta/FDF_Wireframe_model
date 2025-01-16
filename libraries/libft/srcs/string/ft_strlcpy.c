/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:57:20 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 12:41:16 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*
int main(void)
{
	char src[] = "Hello, World!";
	char dst[20];
	size_t size = 20;
	size_t copied;

	copied = ft_strlcpy(dst, src, size);
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dst);
	printf("Length of source: %zu\n", copied);

	return 0;
}
*/