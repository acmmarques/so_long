/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:05:55 by andcardo          #+#    #+#             */
/*   Updated: 2025/11/26 20:32:15 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_number_of_arguments_invalid(int argc)
{
	if (argc != 2)
	{
		print_error("Wrong number of arguments");
		return (1);
	}
	return (0);
}

static int	is_file_descriptor_invalid(int fd)
{
	if (fd < 0)
	{
		print_error("Could not open file on that path");
		return (1);
	}
	return (0);
}

static int	is_file_not_a_ber_file(char *filename)
{
	size_t	len;
	char	*last_four_letters;

	len = ft_strlen(filename);
	if (len < 4)
	{
		print_error("The provided file is not a .ber file");
		return (1);
	}
	last_four_letters = filename + len - 4;
	if (ft_strncmp(last_four_letters, ".ber", 4) != 0)
	{
		print_error("The provided file is not a .ber file");
		return (1);
	}
	return (0);
}

int	validate_input(int argc, char *filename)
{
	int	fd;

	if (is_number_of_arguments_invalid(argc))
		return (0);
	fd = open(filename, O_RDONLY);
	if (is_file_descriptor_invalid(fd))
		return (0);
	if (is_file_not_a_ber_file(filename))
		return (0);
	close(fd);
	return (1);
}
