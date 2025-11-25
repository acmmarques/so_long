/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:40:00 by andcardo          #+#    #+#             */
/*   Updated: 2025/05/07 11:15:37 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	total_size;
	char	*concat_str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total_size = len_s1 + len_s2;
	concat_str = (char *)malloc(sizeof(char) * (total_size + 1));
	if (!concat_str)
		return (NULL);
	ft_memcpy(concat_str, s1, len_s1);
	ft_memcpy(concat_str + len_s1, s2, len_s2);
	concat_str[total_size] = '\0';
	return (concat_str);
}

/*
int main (void)
{
	printf("1st test ->\t");
	char *s1 = ft_strjoin("hello ", "world");
	printf("%s\n", s1);
	printf("2nd test ->\t");
	s1 = ft_strjoin("     ", "hello");
	printf("%s\n", s1);
	printf("3rd test ->\t");
	s1 = ft_strjoin("", "");
	printf("%s\n", s1);
	printf("4th test ->\t");
	s1 = ft_strjoin(NULL, "");
	printf("%s\n", s1);
}
 */
