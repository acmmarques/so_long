/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:37:08 by andcardo          #+#    #+#             */
/*   Updated: 2025/12/01 17:05:17 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && len > 0)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (len - j > 0))
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
		len--;
	}
	return (NULL);
}

static char	*read_file_content(char *filename)
{
	int		fd;
	int		bytes_read;
	char	*big_str;
	char	*temp_buffer;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	temp_buffer = malloc(sizeof(char) * 101);
	if (!temp_buffer)
		return (close(fd), NULL);
	big_str = ft_strdup("");
	while (1)
	{
		bytes_read = read(fd, temp_buffer, 100);
		if (bytes_read <= 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		big_str = ft_strjoin_free(big_str, temp_buffer);
	}
	free(temp_buffer);
	close (fd);
	return (big_str);
}

int	parse_map(char *filename, t_game *game)
{
	char	*raw_map;

	raw_map = read_file_content(filename);
	if (!raw_map)
		return (print_error("Could not parse map"), 0);
	if (ft_strnstr(raw_map, "\n\n", ft_strlen(raw_map)) != NULL)
		return (print_error("Invalid map. One or more empty lines"), 0);
	game->map = ft_split(raw_map, '\n');
	free(raw_map);
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	if (game->height > 0)
		game->width = ft_strlen(game->map[0]);
	else
		game->width = 0;
	return (1);
}
