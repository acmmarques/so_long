/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:23:31 by andcardo          #+#    #+#             */
/*   Updated: 2025/05/14 16:02:20 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*dest_ptr;
	const unsigned char		*src_ptr;

	if (!dest && !src)
		return (dest);
	dest_ptr = dest;
	src_ptr = src;
	while (n--)
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
	}
	return (dest);
}
/*
int main(void)
{
	memcpy(NULL, NULL, 0);
}

*/
