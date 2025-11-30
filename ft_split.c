/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:21:04 by andcardo          #+#    #+#             */
/*   Updated: 2025/11/29 23:38:57 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*save_word(char const *s, char c)
{
	size_t	word_len;
	char	*word;

	word_len = 0;
	while (s[word_len] && s[word_len] != c)
		word_len++;
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, word_len + 1);
	return (word);
}

static void	free_array_split(char **word_array, int counter)
{
	while (counter--)
		free(word_array[counter]);
	free(word_array);
}

static char	**split_str(char const *s, char c, char **word_array, int word_nb)
{
	int		j;

	j = 0;
	while (*s && j < word_nb)
	{
		while (*s && *s == c)
			s++;
		if (*s != '\0')
		{
			word_array[j] = save_word(s, c);
			if (!word_array[j])
			{
				free_array_split(word_array, j);
				return (NULL);
			}
			j++;
		}
		while (*s && *s != c)
			s++;
	}
	word_array[j] = NULL;
	return (word_array);
}

char	**ft_split(char const *s, char c)
{
	char	**word_array;
	int		word_nb;

	if (!s)
		return (NULL);
	word_nb = count_words(s, c);
	word_array = (char **)malloc((word_nb + 1) * sizeof(char *));
	if (!word_array)
		return (NULL);
	word_array = split_str(s, c, word_array, word_nb);
	return (word_array);
}
