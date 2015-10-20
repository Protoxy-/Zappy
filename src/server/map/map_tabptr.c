/*
** map_tabptr.c for zappy in /home/alex/rendu/zappy/src/server/map
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Thu Jun 18 17:29:02 2015 Alexandre PAGE
** Last update Fri Jul  3 15:43:34 2015 Maxime JUNGER
*/

#include <server/server.h>

void	map_init_tabptr2(bool (*maptabptrfunc[])())
{
  maptabptrfunc[7] = &dec_food;
  maptabptrfunc[8] = &dec_linemate;
  maptabptrfunc[9] = &dec_deraumere;
  maptabptrfunc[10] = &dec_sibur;
  maptabptrfunc[11] = &dec_mendiane;
  maptabptrfunc[12] = &dec_phiras;
  maptabptrfunc[13] = &dec_thystame;
  maptabptrfunc[(NBR_STONE * 2)] = NULL;
}

void	map_init_tabptr(bool (*maptabptrfunc[])())
{
  maptabptrfunc[0] = &inc_food;
  maptabptrfunc[1] = &inc_linemate;
  maptabptrfunc[2] = &inc_deraumere;
  maptabptrfunc[3] = &inc_sibur;
  maptabptrfunc[4] = &inc_mendiane;
  maptabptrfunc[5] = &inc_phiras;
  maptabptrfunc[6] = &inc_thystame;
  maptabptrfunc[NBR_STONE] = NULL;
}

bool	inc_linemate(t_map *map)
{
  map->linemate += 1;
  return (TRUE);
}

bool	inc_deraumere(t_map *map)
{
  map->deraumere += 1;
  return (TRUE);
}

bool	inc_food(t_map *map)
{
  map->food += 1;
  return (TRUE);
}
