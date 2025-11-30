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

static void	update_positions_on_map(t_game *game, int next_x, int next_y)
{
	char	current_tile;
	char	next_tile;

	current_tile = game->map[game->player_y][game->player_x];
	next_tile = game->map[next_y][next_x];
	if (next_tile == 'E')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[next_y][next_x] = 'R';
	}
	else if (current_tile == 'R')
	{
		game->map[game->player_y][game->player_x] = 'E';
		game->map[next_y][next_x] = 'P';
	}
	else
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[next_y][next_x] = 'P';
	}
	game->player_y = next_y;
	game->player_x = next_x;
	game->player_moves++;
}

static void	print_player_moves(int moves)
{
	char	*number_string;

	number_string = ft_itoa(moves);
	(void)write(1, "Moves: ", 7);
	(void)write(1, number_string, ft_strlen(number_string));
	(void)write(1, "\n", 1);
}

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
	if (next_tile == 'E' && game->collectibles_count == 0)
	{
		(void)write(1, "You won! ", 9);
		game->player_moves++;
		print_player_moves(game->player_moves);
		close_game(game);
	}
	update_positions_on_map(game, next_x, next_y);
	print_player_moves(game->player_moves);
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
