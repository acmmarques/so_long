/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:43:12 by andcardo          #+#    #+#             */
/*   Updated: 2025/05/07 14:18:35 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*find_start(char const *s1, char const *set)
{
	size_t	j;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0' && set[j] != s1[i])
			j++;
		if (set[j] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return ((char *)&s1[i]);
}

static char	*find_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = (int)ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j] != '\0' && set[j] != s1[i])
			j++;
		if (set[j] == '\0')
			return ((char *)&s1[i]);
		i--;
	}
	return ((char *)(s1 - 1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*trimmed;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	end = find_end(s1, set);
	len = 0;
	if (end >= start)
		len = end - start + 1;
	trimmed = (char *)malloc(sizeof(char) * (len + 1));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, start, len + 1);
	return (trimmed);
}

/*
int main(void)
{
	char	*s1 = ft_strtrim("llllzzzzaaahetazztllozl", "lz");
	printf("%s\n", s1);
}
 */
