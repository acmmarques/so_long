/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:23:02 by andcardo          #+#    #+#             */
/*   Updated: 2025/05/05 16:16:44 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr_ptr;

	if (!s || len == 0 || start >= (unsigned int)ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > (unsigned long)ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr_ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr_ptr == NULL)
		return (NULL);
	ft_strlcpy(substr_ptr, s + start, len + 1);
	return (substr_ptr);
}

/*
int	main(void)
{
	//char *s1 = ft_substr(NULL, 0, 0);
	char *s2 = ft_substr("Juliao Bolseiro não sabe nadar yo", 0, 20);	
	//char *s3 = ft_substr("hola", 4294967295, 0);
	printf("%s\n", s2);
}
 */
