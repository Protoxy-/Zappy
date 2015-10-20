/*
** ebo.c for zappy in /home/alexandre/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Sat Jun 27 18:33:44 2015 Alexandre PAGE
** Last update Fri Jul  3 14:47:18 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/lib.h>

void	ebo(t_env *e, t_players *player)
{
  char	*str;

  asprintf(&str, "ebo %d\n", player->idegg);
  send_mess_graphic_client(e, str);
}
