/*
** tna.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Sun Jun 21 11:31:04 2015 Alexandre PAGE
** Last update Fri Jul  3 15:02:41 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/commands.h>
#include <server/parser.h>
#include <server/lib.h>

void		tna(t_env *client, int fd, char **arg)
{
  t_teams	*tmp;
  char		*str;

  (void) arg;
  tmp = client->parser->teams->next;
  while (tmp != client->parser->teams)
    {
      asprintf(&str, "tna %s\n", tmp->name);
      write_on_client(str, fd);
      xfree(str);
      tmp = tmp->next;
    }
}
