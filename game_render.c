/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:36:34 by andcardo          #+#    #+#             */
/*   Updated: 2025/11/28 00:53:27 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		img, x * TILE_SIZE, y * TILE_SIZE);
}

int	render_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			put_image(game, game->floor_img, j, i);
			if (game->map[i][j] == '1')
				put_image(game, game->wall_img, j, i);
			else if (game->map[i][j] == 'P')
				put_image(game, game->player_img, j, i);
			else if (game->map[i][j] == 'C')
				put_image(game, game->collectible_img, j, i);
			else if (game->map[i][j] == 'E')
				put_image(game, game->exit_img, j, i);
			j++;
		}
		i++;
	}
	return (1);
}
