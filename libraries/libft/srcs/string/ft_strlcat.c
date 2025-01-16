/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:14:03 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 12:27:06 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (len_dst >= size)
		return (len_src + size);
	while (i < size - len_dst - 1 && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
/*
int main()
{
	char dest[50] = "Hello, ";
	const char *src = "world!";
	size_t size = 50;
	size_t result;

	result = ft_strlcat(dest, src, size);
	printf("Resulting string: %s\n", dest);
	printf("Total length: %zu\n", result);

	return 0;
}
*/