/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:05:38 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 12:41:08 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_slen;
	char	*strmapi;
	size_t	i;

	s_slen = ft_strlen(s);
	strmapi = malloc(sizeof(char) * (s_slen + 1));
	if (!strmapi)
		return (NULL);
	i = 0;
	while (s[i])
	{
		strmapi[i] = f(i, s[i]);
		i++;
	}
	strmapi[s_slen] = '\0';
	return (strmapi);
}
/*
char sample_function(unsigned int i, char c)
{
	return c + i;
}

int main(void)
{
	char *result;
	char str[] = "Hello";
	
	result = ft_strmapi(str, sample_function);
	if (result)
	{
		printf("Original: %s\n", str);
		printf("Modified: %s\n", result);
		free(result);
	}
	return 0;
}
*/