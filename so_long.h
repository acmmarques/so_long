/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:09:02 by andcardo          #+#    #+#             */
/*   Updated: 2025/11/29 17:16:57 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

# define TILE_SIZE 32
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define ON_KEYDOWN     2
# define ON_KEYUP       3
# define ON_DESTROY     17
# define NO_EVENT_MASK  0

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		collectibles_count;
	int		players_count;
	int		exits_count;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*player_on_exit_img;
	void	*collectible_img;
	void	*exit_img;
	int		player_moves;
}	t_game;

void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		validate_input(int argc, char *filename);
int		parse_map(char *filename, t_game *game);
void	print_error(char *message);
void	print_to_fd(char *str, int fd);
char	*ft_strjoin_free(char *s1, char *s2);
void	free_map(t_game *game);
void	free_array(char **array, int height);
int		validate_map(t_game *game);
char	**duplicate_map(t_game *game);
void	flood_fill(char **grid, t_game *game, int x, int y);
int		close_game(t_game *game);
int		initialize_game(t_game *game);
int		render_game(t_game *game);
int		handle_keyboard_input(int keysym, t_game *game);
void	update_player_position(t_game *game, int x, int y);

#endif
