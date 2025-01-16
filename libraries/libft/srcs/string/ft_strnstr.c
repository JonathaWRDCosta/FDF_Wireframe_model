/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 04:24:12 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 12:40:46 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			while (little[j] != '\0' && (i + j) < len && big[i
					+ j] == little[j])
			{
				j++;
			}
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	const char *big = "Hello, this is a simple string";
	const char *little = "simple";
	size_t len = 25;
	char *result;

	result = ft_strnstr(big, little, len);
	if (result)
		printf("Found: %s\n", result);
	else
		printf("Not found\n");

	return 0;
}
*/