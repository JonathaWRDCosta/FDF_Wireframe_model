/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 23:17:04 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/18 17:32:05 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



static size_t	count_words(const char *str, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == c)
		{
			if (in_word)
			{
				in_word = 0;
				count++;
			}
		}
		else if (!in_word)
			in_word = 1;
		str++;
	}
	if (in_word)
		count++;
	return (count);
}

static char	*extract_word(const char *str, char c, size_t *index)
{
	const char	*start;
	size_t		length;

	start = str;
	length = 0;
	while (*str && *str != c)
	{
		length++;
		str++;
	}
	*index += length;
	return (ft_substr(start, 0, length));
}

char	**ft_split(const char *s, char c)
{
	size_t	words_count;
	char	**result;
	size_t	index;
	size_t	word_index;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	result = ft_calloc(words_count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	word_index = 0;
	while (s[index])
	{
		if (s[index] == c)
			index++;
		else
		{
			result[word_index] = extract_word(&s[index], c, &index);
			word_index++;
		}
	}
	return (result);
}
/*
int main()
{
    char **result;
    size_t i;

    result = ft_split("Hello world! This is a test.", ' ');
    if (result)
    {
        for (i = 0; result[i]; i++)
        {
            ft_putstr_fd(result[i], 1);
            ft_putstr_fd("\n", 1);
            free(result[i]);
        }
        free(result);
    }
    return 0;
}
*/
