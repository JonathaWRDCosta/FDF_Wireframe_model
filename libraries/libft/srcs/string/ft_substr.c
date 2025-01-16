/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:34:14 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/07 18:10:55 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	t_s = ft_calloc(len + 1, sizeof(char));
	if (t_s == NULL)
		return (NULL);
	while (i < len)
	{
		t_s[i] = s[start + i];
		i++;
	}
	t_s[i] = '\0';
	return (t_s);
}
/*
int main(void)
{
	char *s = "Hello, World!";
	unsigned int start = 7;
	size_t len = 5;
	char *substr;

	substr = ft_substr(s, start, len);
	if (substr)
	{
		printf("Substring: %s\n", substr);
		free(substr);
	}
	else
	{
		printf("Failed to allocate memory for substring.\n");
	}
	return 0;
}
*/