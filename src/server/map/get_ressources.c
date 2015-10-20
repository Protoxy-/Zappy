/*
** get_ressource.c for zappy in /home/alexandre/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Wed Jun 24 23:39:24 2015 Alexandre PAGE
** Last update Fri Jul  3 15:30:58 2015 Maxime JUNGER
*/

#include <server/server.h>
#include <server/socket.h>
#include <server/commands.h>

int	get_food(t_map *map)
{
  return (map->food);
}

int	get_linemate(t_map *map)
{
  return (map->linemate);
}

int	get_deraumere(t_map *map)
{
  return (map->deraumere);
}

int	get_sibur(t_map *map)
{
  return (map->sibur);
}

int	get_mendiane(t_map *map)
{
  return (map->mendiane);
}
