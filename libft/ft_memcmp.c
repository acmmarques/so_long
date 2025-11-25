/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:09:28 by andcardo          #+#    #+#             */
/*   Updated: 2025/04/30 09:53:08 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*one;
	const unsigned char	*two;

	if (n == 0)
		return (0);
	one = (const unsigned char *)s1;
	two = (const unsigned char *)s2;
	while (n > 1 && *one == *two)
	{
		one++;
		two++;
		n--;
	}
	return (*one - *two);
}

/*

int	main(void)
{
	int c = ft_memcmp("hf", "hx", 1);
	printf("c: %d\n", c);
}
	*/