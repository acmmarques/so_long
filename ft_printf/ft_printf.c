/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:59:14 by andcardo          #+#    #+#             */
/*   Updated: 2025/07/27 10:33:30 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_specifier(char specifier, va_list *args, size_t *char_count);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	char_count;
	size_t	i;
	char	*sp_list;

	if (!format)
		return (-1);
	char_count = 0;
	i = 0;
	sp_list = "cspdiuxX%";
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr(sp_list, format[i + 1]))
		{
			i++;
			handle_specifier(format[i], &args, &char_count);
		}
		else
			ft_putchar(format[i], &char_count);
		i++;
	}
	va_end(args);
	return (char_count);
}

static void	handle_specifier(char sp, va_list *args, size_t *char_count)
{
	if (sp == 'c')
		ft_putchar((char)va_arg(*args, int), char_count);
	else if (sp == 's')
		ft_putstr(va_arg(*args, char *), char_count);
	else if (sp == 'p')
		ft_putphex(va_arg(*args, void *), char_count);
	else if (sp == 'd' || sp == 'i')
		ft_putnbr(va_arg(*args, int), char_count);
	else if (sp == 'u')
		ft_putunbr(va_arg(*args, unsigned int), char_count);
	else if (sp == 'x' || sp == 'X')
		ft_puthex(va_arg(*args, unsigned int), char_count, sp);
	else if (sp == '%')
		ft_putchar(sp, char_count);
}
