/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:32:14 by andcardo          #+#    #+#             */
/*   Updated: 2025/11/27 14:59:28 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **grid, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (grid[y][x] == 'X' || grid[y][x] == '1')
		return ;
	grid[y][x] = 'X';
	flood_fill(grid, game, x + 1, y);
	flood_fill(grid, game, x - 1, y);
	flood_fill(grid, game, x, y + 1);
	flood_fill(grid, game, x, y - 1);
}

void	update_player_position(t_game *game, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
}

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
