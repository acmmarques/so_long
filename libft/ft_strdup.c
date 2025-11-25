/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:15:03 by andcardo          #+#    #+#             */
/*   Updated: 2025/04/30 15:55:26 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	str_len;
	char	*dest;

	str_len = ft_strlen(s1);
	dest = (char *)malloc((str_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, str_len + 1);
	return (dest);
}

/*
int	main(void)
{
	char *str = ft_strdup("constantemente adrelina");
	printf("%s\n", str);
	printf("%p\n", str);
	str = strdup("constantemente adrelina");
	printf("%s\n", str);
	printf("%p\n", str);
}
 */
