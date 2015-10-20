/*
** smg.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Mon Jun 22 17:58:37 2015 Alexandre PAGE
** Last update Fri Jul  3 15:02:19 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>
#include <server/lib.h>

void	smg(int fd, char *message)
{
  char	*str;

  asprintf(&str, "smg %s\n", message);
  write_on_client(str, fd);
  xfree(str);
}
