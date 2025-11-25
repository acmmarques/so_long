/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:56:32 by andcardo          #+#    #+#             */
/*   Updated: 2025/05/09 14:38:50 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	my_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static void	ft_add_whitespaces(const char *str, int *i)
{
	while (str[*i] == ' '
		|| (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	i = 0;
	ft_add_whitespaces(str, &i);
	if ((str[i] == '-' || str[i] == '+')
		&& (my_isdigit(str[i + 1])))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while (my_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

/* int	main(void)
{
	char *str = "\t\n -46546";
	printf("atoi: %i\n", atoi(str));
	printf("ft_atoi: %i\n",ft_atoi(str));
} */