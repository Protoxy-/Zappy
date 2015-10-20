/*
** level1.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/levels
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Sat Jun 27 11:44:09 2015 Maxime JUNGER
** Last update Fri Jul  3 15:13:45 2015 Maxime JUNGER
*/

#include <server/server.h>
#include <server/lib.h>
#include <stdlib.h>

bool	level_1(t_map *map, t_players *list)
{
  if (get_number_players(list) == 1 && map->linemate == 1
      && map->deraumere == 0 && map->sibur == 0 && map->mendiane == 0
      && map->phiras == 0 && map->thystame == 0)
    return (TRUE);
  return (FALSE);
}

bool	level_2(t_map *map, t_players *list)
{
  if (get_number_players(list) == 2 && map->linemate == 1
      && map->deraumere == 1 && map->sibur == 1 && map->mendiane == 0
      && map->phiras == 0 && map->thystame == 0)
    return (TRUE);
  return (FALSE);
}

bool	level_3(t_map *map, t_players *list)
{
  if (get_number_players(list) == 2 && map->linemate == 2
      && map->deraumere == 0 && map->sibur == 1 && map->mendiane == 0
      && map->phiras == 2 && map->thystame == 0)
    return (TRUE);
  return (FALSE);
}

bool	level_4(t_map *map, t_players *list)
{
  if (get_number_players(list) == 4 && map->linemate == 1
      && map->deraumere == 1 && map->sibur == 2 && map->mendiane == 0
      && map->phiras == 1 && map->thystame == 0)
    return (TRUE);
  return (FALSE);
}

bool	level_5(t_map *map, t_players *list)
{
  if (get_number_players(list) == 4 && map->linemate == 1
      && map->deraumere == 2 && map->sibur == 1 && map->mendiane == 3
      && map->phiras == 0 && map->thystame == 0)
    return (TRUE);
  return (FALSE);
}
