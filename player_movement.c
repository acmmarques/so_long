/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:18:50 by andcardo          #+#    #+#             */
/*   Updated: 2025/11/28 16:46:20 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int next_x, int next_y)
{
	char	next_tile;

	next_tile = game->map[next_y][next_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
	{
		game->collectibles_count--;
		game->map[next_y][next_x] = '0';
	}
	if (next_tile == 'E')
	{
		if (game->collectibles_count == 0)
		{
			ft_printf("You won! Moves: %i\n", game->player_moves + 1);
			close_game(game);
		}
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[next_y][next_x] = 'P';
	game->player_y = next_y;
	game->player_x = next_x;
	game->player_moves++;
	ft_printf("Moves: %i\n", game->player_moves + 1);
	render_game(game);
}

int	handle_keyboard_input(int keysym, t_game *game)
{
	if (keysym == KEY_ESC)
		close_game(game);
	else if (keysym == KEY_A || keysym == KEY_LEFT)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keysym == KEY_S || keysym == KEY_DOWN)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keysym == KEY_W || keysym == KEY_UP)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keysym == KEY_D || keysym == KEY_RIGHT)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}
