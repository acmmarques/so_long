/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:36:23 by andcardo          #+#    #+#             */
/*   Updated: 2025/04/29 17:05:15 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	c = (unsigned char)c;
	ptr = (const unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == c)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

/*
int	main(void)
{
	char *b = ft_memchr("unitz", 'z', 4);
	char *c = memchr("unitz", 'z', 4);
	printf("pointer: %p \tvalue: %c\n", b, *b);
	printf("pointer: %p \tvalue: %c\n", c, *c);
}
 */
