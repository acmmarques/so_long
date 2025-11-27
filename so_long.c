#include "so_long.h"

int main(int argc, char *argv[])
{
  t_game  game;

  //Setting every byte of the struct to 0
  //Now I can increment integers without
  //assigning them to 0 first
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

  ft_printf("game height: %i\n", game.height);
  ft_printf("game len: %i\n", game.width);
  free_map(&game);
  ft_printf("End of program\n");
  return(0);
}
