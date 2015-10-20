/*
** msz.c for zappy in /home/alex/rendu/zappy/src/server
** 
** Made by page_a
** Login   <alex@epitech.net>
** 
** Started on  Fri May  1 14:56:54 2015 page_a
** Last update Fri Jul  3 14:52:09 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>

void	msz(t_env *client, int client_fd, char **arg)
{
  int	height;
  int	width;
  char	*str;

  (void)arg;
  height = client->parser->height;
  width = client->parser->width;
  asprintf(&str, "msz %d %d\n", width, height);
  write_on_client(str, client_fd);
}
