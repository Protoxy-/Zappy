/*
** get_ressources_func.c for zappy in /home/alexandre/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Thu Jun 25 09:17:51 2015 Alexandre PAGE
** Last update Sun Jul  5 13:13:20 2015 Alexandre PAGE
*/

#include <server/server.h>

int	get_phiras(t_map *map)
{
  return (map->phiras);
}

int	get_thystame(t_map *map)
{
  return (map->thystame);
}

int	get_player(t_players *players, int x, int y)
{
  t_players *player;
  int   i;

  i = 0;
  player = players->next;
  while (player != players)
    {
      if (player->playerx == x && player->playery == y)
        i = i + 1;
      player = player->next;
    }
  return (i);
}
