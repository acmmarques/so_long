/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:38:30 by andcardo          #+#    #+#             */
/*   Updated: 2025/05/05 16:43:09 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	while (i < size && dst[i] != '\0')
		i++;
	dst_len = i;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len + dst_len);
	j = 0;
	while (src[j] != '\0' && (j + dst_len < size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (size > dst_len)
		dst[i] = '\0';
	return (src_len + dst_len);
}
