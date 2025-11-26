#include "so_long.h"

int main(int argc, char *argv[])
{
  t_game  game;

  if (!validate_input(argc, argv[1]))
    return (1);
  if (!parse_map(argv[1], &game))
    return (1);
  if (!validate_map(&game))
    return (1);

  ft_printf("game height: %i\n", game.height);
  ft_printf("game len: %i\n", game.width);
  free_map(&game);
  ft_printf("End of program\n");
  return(0);
}
