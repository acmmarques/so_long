/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:23:31 by andcardo          #+#    #+#             */
/*   Updated: 2025/11/26 20:22:53 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  print_error(char *message)
{
  ft_printf("Error\n%s\n", message);
}

char  *ft_strjoin_free(char *s1, char *s2)
{
  char *new_str;

  new_str = ft_strjoin(s1, s2);
  free(s1);
  return (new_str);
}

void  free_map(t_game *game)
{
  int i;

  if (!game->map)
    return;
  i = 0;
  while (i < game->height)
  {
    if (game->map[i])
      free(game->map[i]);
    i++;
  }
  free(game->map);
  game->map = NULL;
}
