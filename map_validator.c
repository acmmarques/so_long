/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:58:56 by andcardo          #+#    #+#             */
/*   Updated: 2025/11/27 15:11:21 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_map_structure(t_game *game)
{
	int	i;

	if (game->height == 0)
		return (0);
	i = 0;
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i]) != game-> width)
			return (0);
		i++;
	}
	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	count_map_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				game->collectibles_count++;
			else if (game->map[i][j] == 'P')
			{
				game->players_count++;
				game->player_y = i;
				game->player_x = j;
			}
			else if (game->map[i][j] == 'E')
				game->exits_count++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	validate_map_content(t_game *game)
{
	if (!count_map_elements(game))
		return (0);
	if (game->players_count != 1
		|| game->exits_count != 1
		|| game->collectibles_count < 1)
		return (0);
	return (1);
}

static int	validate_map_path(t_game *game)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = duplicate_map(game);
	flood_fill(map_copy, game, game->player_x, game->player_y);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
			{
				free_array(map_copy, game->height);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_array(map_copy, game->height);
	return (1);
}

int	validate_map(t_game *game)
{
	if (!validate_map_structure(game))
	{
		print_error("The map doesn't have the proper structure");
		return (0);
	}
	if (!validate_map_content(game))
	{
		print_error("There was a problem with the map's content");
		return (0);
	}
	if (!validate_map_path(game))
	{
		print_error("The map is not valid. Could not find a solvable path");
		return (0);
	}
	return (1);
}
