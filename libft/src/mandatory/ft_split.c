/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:40:48 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 23:03:41 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*splits a string into an array of substrings using c as delimiter.*/

static size_t	count_words(const char *s, int c)
{
	size_t	wc;
	int		in_word;

	in_word = 0;
	wc = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			wc++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (wc);
}

static int	fill_result(char **result, char const *s, char c, size_t *i)
{
	size_t	start;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	*result = ft_substr(s, start, (*i - start));
	if (!result)
		return (0);
	return (1);
}

static char	**free_all(char **array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;

	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			if (!fill_result(&result[j], s, c, &i))
				return (free_all(result, j));
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}
