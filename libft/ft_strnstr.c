/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:32:39 by andcardo          #+#    #+#             */
/*   Updated: 2025/04/30 09:49:57 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && len > 0)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (len - j > 0))
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
		len--;
	}
	return (NULL);
}

/*
int	main(void)
{
	char *ptr = ft_strnstr("Foo Bar Zen", "Bar", 6);
	printf("ptr = %p\n", ptr);
	//printf("ptr = %c\n", *ptr);
}
*/
