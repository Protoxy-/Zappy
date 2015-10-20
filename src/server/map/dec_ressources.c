/*
** dec_ressource.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Tue Jun 23 10:55:48 2015 Alexandre PAGE
** Last update Fri Jul  3 15:30:13 2015 Maxime JUNGER
*/

#include <server/server.h>

bool	dec_linemate(t_map *map)
{
  if (map->linemate > 0)
    {
      map->linemate -= 1;
      return (TRUE);
    }
  return (FALSE);
}

bool	dec_deraumere(t_map *map)
{
  if (map->deraumere > 0)
    {
      map->deraumere -= 1;
      return (TRUE);
    }
  return (FALSE);
}

bool	dec_food(t_map *map)
{
  if (map->food > 0)
    {
      map->food -= 1;
      return (TRUE);
    }
  return (FALSE);
}

bool	dec_sibur(t_map *map)
{
  if (map->sibur > 0)
    {
      map->sibur -= 1;
      return (TRUE);
    }
  return (FALSE);
}

bool	dec_mendiane(t_map *map)
{
  if (map->mendiane > 0)
    {
      map->mendiane -= 1;
      return (TRUE);
    }
  return (FALSE);
}
