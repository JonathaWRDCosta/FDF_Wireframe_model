/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 04:01:05 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 12:40:40 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	t_c;

	len = ft_strlen(s);
	t_c = (unsigned char)c;
	if (t_c == '\0')
		return ((char *)&s[len]);
	while (len > 0)
	{
		if (s[len - 1] == t_c)
			return ((char *)&s[len - 1]);
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[];
	char		ch;
	char		*result;

	str[] = "Hello, world!";
	ch = 'o';
	result = ft_strrchr(str, ch);
	if (result != NULL)
		printf("The last occurrence of '%c' in \"%s\" is at position: %ld\n",
				ch, str, result - str);
	else
		printf("Character '%c' not found in \"%s\"\n", ch, str);
	return (0);
}
*/
