/*
** map_func_stone.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Thu Jun 18 18:09:09 2015 Alexandre PAGE
** Last update Fri Jul  3 15:40:29 2015 Maxime JUNGER
*/

#include <server/server.h>

bool	inc_sibur(t_map *map)
{
  map->sibur += 1;
  return (TRUE);
}

bool	inc_mendiane(t_map *map)
{
  map->mendiane += 1;
  return (TRUE);
}

bool	inc_phiras(t_map *map)
{
  map->phiras += 1;
  return (TRUE);
}

bool	inc_thystame(t_map *map)
{
  map->thystame += 1;
  return (TRUE);
}
