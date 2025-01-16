/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 03:26:38 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/07 18:01:10 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*t_s1;
	size_t	i;

	i = 0;
	t_s1 = (char *)malloc(ft_strlen(s1) + 1);
	if (t_s1 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		t_s1[i] = s1[i];
		i++;
	}
	t_s1[i] = '\0';
	return (t_s1);
}
/*
int main(void)
{
	char *str1 = "Hello, World!";
	char *str2 = "";
	char *str3 = NULL;
	char *dup1;
	char *dup2;
	char *dup3;

	dup1 = ft_strdup(str1);
	dup2 = ft_strdup(str2);
	dup3 = ft_strdup(str3);

	if (dup1)
		printf("Original: %s, Duplicate: %s\n", str1, dup1);
	else
		printf("Failed to duplicate str1\n");

	if (dup2)
		printf("Original: %s, Duplicate: %s\n", str2, dup2);
	else
		printf("Failed to duplicate str2\n");

	if (dup3)
		printf("Original: %s, Duplicate: %s\n", str3, dup3);
	else
		printf("Failed to duplicate str3\n");

	free(dup1);
	free(dup2);
	free(dup3);

	return 0;
}
*/