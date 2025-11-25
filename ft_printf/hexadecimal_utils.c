/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:54:53 by andcardo          #+#    #+#             */
/*   Updated: 2025/07/26 23:24:48 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static void	hex_calc(unsigned long int nbr, char *base, size_t *char_count);

void	ft_puthex(unsigned long int nbr, size_t *char_count, char base_format)
{
	char	*base;

	if (base_format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	hex_calc(nbr, base, char_count);
}

void	ft_putphex(void *address, size_t *char_count)
{
	if (!address)
		return (ft_putstr("(nil)", char_count));
	ft_putchar('0', char_count);
	ft_putchar('x', char_count);
	ft_puthex((unsigned long int)address, char_count, 'x');
}

static void	hex_calc(unsigned long int nbr, char *base, size_t *char_count)
{
	if (nbr > 15)
	{
		hex_calc(nbr / 16, base, char_count);
	}
	ft_putchar(base[nbr % 16], char_count);
}
