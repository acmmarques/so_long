/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:10:06 by andcardo          #+#    #+#             */
/*   Updated: 2025/05/09 14:30:21 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb && nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	ptr = (void *)malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

/*
int	main(void)
{
	printf("Hello from main\n");
	char *str = (char *)ft_calloc(30, 1);
	int i = 0;
	while (i < 30)
	{
		printf("p[%i] = %p\t", i, str);
		printf("%i\n", *str);
		i++;
		str++;
	}
}
 */
