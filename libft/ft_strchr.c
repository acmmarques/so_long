/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:12:28 by andcardo          #+#    #+#             */
/*   Updated: 2025/05/09 15:11:56 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)&(s[i]));
	return ((char *)0);
}

/*
int	main (void)
{
	char *s = ft_strchr("hello", 'z');
	char *d = strchr("hello", 'z');
	//
	printf("%p\n", (s));
	printf("%p\n", (d));
}
 */
