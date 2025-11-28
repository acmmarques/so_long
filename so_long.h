#ifndef SO_LONG
# define SO_LONG

# include <fcntl.h>
# include "mlx.h"
# include "ft_printf.h"
# include "libft.h"

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

typedef struct s_game
{
  void  *mlx_ptr;
  void  *win_ptr;
  char  **map;
  int   height;
  int   width;
  int   player_x;
  int   player_y;
  int   collectibles_count;
  int   players_count;
  int   exits_count;
  void  *wall_img;
  void  *floor_img;
  void  *player_img;
  void  *collectible_img;
  void  *exit_img;
  int   player_moves;
  int   exit_reached;
} t_game;

int   validate_input(int argc, char *filename);
int   parse_map(char *filename, t_game *game);
void  print_error(char *message);
char  *ft_strjoin_free(char *s1, char *s2);
void  free_map(t_game *game);
void  free_array(char **array, int height);
int   validate_map(t_game *game);
char **duplicate_map(t_game *game);
void  flood_fill(char **grid, t_game *game, int x, int y);
int  close_game(t_game *game);
int initialize_game(t_game *game);
int render_game(t_game *game);

#endif
