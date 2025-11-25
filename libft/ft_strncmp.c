/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:48:08 by andcardo          #+#    #+#             */
/*   Updated: 2025/04/29 16:35:27 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i]
		&& (i < n - 1)
		&& (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int main(void)
{
	char *one = "zyxbcdefgh";
	char *two = "abcdwxyz";
	int a = ft_strncmp(one, two, 0);
	int b = strncmp(one, two, 0);
	printf("dif->%d\n", a);
	printf("dif->%d\n", b);
}
 */
