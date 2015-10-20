/*
** level6-7.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/levels
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Sat Jun 27 12:01:45 2015 Maxime JUNGER
** Last update Fri Jul  3 15:14:01 2015 Maxime JUNGER
*/

#include <server/server.h>
#include <server/lib.h>
#include <stdlib.h>

bool	level_6(t_map *map, t_players *list)
{
  if (get_number_players(list) == 6 && map->linemate == 1
      && map->deraumere == 2 && map->sibur == 3 && map->mendiane == 0
      && map->phiras == 1 && map->thystame == 0)
    return (TRUE);
  return (FALSE);
}

bool	level_7(t_map *map, t_players *list)
{
  if (get_number_players(list) == 6 && map->linemate == 2
      && map->deraumere == 2 && map->sibur == 2 && map->mendiane == 2
      && map->phiras == 2 && map->thystame == 1)
    return (TRUE);
  return (FALSE);
}
