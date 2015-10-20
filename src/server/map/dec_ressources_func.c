/*
** dec_ressource_func.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Tue Jun 23 10:57:40 2015 Alexandre PAGE
** Last update Fri Jul  3 15:30:30 2015 Maxime JUNGER
*/

#include <server/socket.h>

bool	dec_phiras(t_map *map)
{
  if (map->phiras > 0)
    {
      map->phiras -= 1;
      return (TRUE);
    }
  return (FALSE);
}

bool	dec_thystame(t_map *map)
{
  if (map->thystame > 0)
    {
      map->thystame -= 1;
      return (TRUE);
    }
  return (FALSE);
}
