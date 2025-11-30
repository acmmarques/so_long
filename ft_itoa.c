/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:40:13 by andcardo          #+#    #+#             */
/*   Updated: 2025/11/29 23:38:40 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	fill_str_backwards(char *s, long nb, int index)
{
	while (nb > 0)
	{
		s[index--] = nb % 10 + '0';
		nb /= 10;
	}
}

static	int	find_nb_of_digits(long n)
{
	int	digit_nb;

	digit_nb = 1;
	if (n < 0)
	{
		digit_nb += 1;
		n *= -1;
	}
	while (n > 9)
	{
		digit_nb ++;
		n /= 10;
	}
	return (digit_nb);
}

char	*ft_itoa(int n)
{
	int		digit_nb;
	long	nb;
	char	*str;

	nb = (long)n;
	digit_nb = find_nb_of_digits(nb);
	str = (char *)malloc((digit_nb + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[digit_nb--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	fill_str_backwards(str, nb, digit_nb);
	return (str);
}
