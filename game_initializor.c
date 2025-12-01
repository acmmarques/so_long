/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initializor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:04:49 by andcardo          #+#    #+#             */
/*   Updated: 2025/12/01 19:29:46 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_sprite(t_game *game, char *path)
{
	int		x;
	int		y;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx_ptr, path, &x, &y);
	if (!img)
	{
		print_error("Failed to load texture.");
		return (NULL);
	}
	return (img);
}

static void	free_assets(t_game *game)
{
	if (game->floor_img)
		mlx_destroy_image(game->mlx_ptr, game->floor_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx_ptr, game->wall_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx_ptr, game->player_img);
	if (game->player_on_exit_img)
		mlx_destroy_image(game->mlx_ptr, game->player_on_exit_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx_ptr, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx_ptr, game->exit_img);
}

static int	initialize_assets(t_game *game)
{
	game->floor_img = load_sprite(game, "textures/floor.xpm");
	game->wall_img = load_sprite(game, "textures/wall.xpm");
	game->exit_img = load_sprite(game, "textures/exit.xpm");
	game->player_img = load_sprite(game, "textures/player.xpm");
	game->player_on_exit_img = load_sprite(game, "textures/player_on_exit.xpm");
	game->collectible_img = load_sprite(game, "textures/collectible.xpm");
	if (!game->floor_img || !game->wall_img || !game->exit_img
		|| !game->player_img || !game->collectible_img)
	{
		free_assets(game);
		return (0);
	}
	return (1);
}

int	close_game(t_game *game)
{
	free_assets(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free_map(game);
	exit(0);
	return (0);
}

int	initialize_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		print_error("Couldn't start game. Failed to initialize MiniLibX");
		return (0);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->width * TILE_SIZE,
			game->height * TILE_SIZE,
			"The Goated So Long");
	if (!game->win_ptr)
	{
		print_error("Couldn't start game. Failed to create window");
		return (0);
	}
	if (!initialize_assets(game))
		return (0);
	return (1);
}
