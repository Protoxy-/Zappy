/*
** sbp.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Fri Jun 19 22:55:34 2015 Alexandre PAGE
** Last update Fri Jul  3 15:04:10 2015 Maxime JUNGER
*/

#include <server/server.h>
#include <server/socket.h>
#include <server/commands.h>

void	sbp(t_env *client, int fd, char **arg)
{
  (void)client;
  (void)arg;
  write_on_client("sbp\n", fd);
}
