#include "so_long.h"

int main(int argc, char *argv[])
{
  t_game  game;
  ft_bzero(&game, sizeof(t_game));
  if (!validate_input(argc, argv[1]))
    return (1);
  if (!parse_map(argv[1], &game))
    return (1);
  if (!validate_map(&game))
  {
    free_map(&game);
    return (1);
  }
  if (!initialize_game(&game))
    close_game(&game);
  if (!render_game(&game))
    close_game(&game);
  mlx_key_hook(game.win_ptr, handle_keyboard_input, &game);
  mlx_hook(game.win_ptr, ON_DESTROY, NO_EVENT_MASK, close_game, &game);
  mlx_loop(game.mlx_ptr);
  return(0);
}
