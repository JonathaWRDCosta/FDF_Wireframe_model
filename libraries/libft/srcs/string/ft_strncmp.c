/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 03:25:23 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 12:41:00 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] == '\0' || (unsigned char)s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[];
	char	str2[];
	char	str3[];
	size_t	n;

	str1[] = "Hello";
	str2[] = "Hello";
	str3[] = "Hellp";
	n = 5;
	printf("Comparing '%s' and '%s' for first %zu characters: %d\n", str1, str2,
			n, ft_strncmp(str1, str2, n));
	printf("Comparing '%s' and '%s' for first %zu characters: %d\n", str1, str3,
			n, ft_strncmp(str1, str3, n));
	printf("Comparing '%s' and '%s' for first %zu characters: %d\n", str2, str3,
			n, ft_strncmp(str2, str3, n));
	return (0);
}
*/
