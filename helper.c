/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:23:31 by andcardo          #+#    #+#             */
/*   Updated: 2025/11/27 13:30:53 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *message)
{
	ft_printf("Error\n%s\n", message);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	free(s1);
	return (new_str);
}

void	free_array(char **array, int height)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < height)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

void	free_map(t_game *game)
{
	if (!game->map)
		return ;
	free_array(game->map, game->height);
	game->map = NULL;
}

char	**duplicate_map(t_game *game)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		return (NULL);
	while (i < game->height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			free_array(map_copy, i);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}
