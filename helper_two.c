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

void  flood_fill(char **grid, t_game *game, int x, int y)
{
  if (x < 0 || y < 0 || x >= game->width || y >= game->height)
    return;
  if (grid[y][x] == 'X' || grid[y][x] == '1')
    return;
  grid[y][x] = 'X';
  flood_fill(grid, game, x + 1, y);
  flood_fill(grid, game, x - 1, y);
  flood_fill(grid, game, x, y + 1);
  flood_fill(grid, game, x, y - 1);
}
