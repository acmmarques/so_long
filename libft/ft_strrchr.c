/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:19:17 by andcardo          #+#    #+#             */
/*   Updated: 2025/05/09 15:13:08 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	c = (char)c;
	len = ft_strlen(s);
	if (s[len] == '\0' && c == '\0')
		return ((char *)&(s[len]));
	while (len > 0)
	{
		if (s[len - 1] == c)
			return ((char *)&(s[len - 1]));
		len--;
	}
	return ((char *) NULL);
}

/*
int	main(void)
{
	//1st test
	printf("1st test - finds c in count\n");
	char *a;
	char *b; 
	a = ft_strrchr("count", 'c');
	b = strrchr("count", 'c');
	if (a == b)
	{
		printf("======================\n");
		printf("Success!\n");
		printf("======================\n");
	}
	else
	{
		printf("======================\n");
		printf("FAILED!\n");
		printf("======================\n");
	}
	//2nd test
	printf("2nd test - finds \\f in Caaacke\\fc\\naslajasCak##aount\n");
	a = ft_strrchr("Caaacke\fc\naslajasCak##aount", '\f');
	b = strrchr("Caaacke\fc\naslajasCak##aount", '\f');
	if (a == b)
	{
		printf("======================\n");
		printf("Success!\n");
		printf("======================\n");
	}
	else
	{
		printf("======================\n");
		printf("FAILED!\n");
		printf("======================\n");
	}
	//3rd test
	printf("3rd test - does not find c in RSSAG88*(00)AGihioh55331\n");
	a = ft_strrchr("RSSAG88*(00)AGihioh55331", 'c');
	b = strrchr("RSSAG88*(00)AGihioh55331", 'c');
	if (a == b)
	{
		printf("======================\n");
		printf("Success!\n");
		printf("======================\n");
	}
	else
	{
		printf("======================\n");
		printf("FAILED!\n");
		printf("======================\n");
	}
}
*/
