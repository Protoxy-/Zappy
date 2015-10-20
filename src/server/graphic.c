/*
** graphic.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Fri Jun 19 14:46:52 2015 Alexandre PAGE
** Last update Fri Jul  3 18:41:24 2015 Maxime JUNGER
*/

#include <server/server.h>
#include <server/socket.h>
#include <server/lib.h>
#include <server/commands.h>

void	send_mess_graphic_client(t_env *e, char *message)
{
  int 	i;

  (void) message;
  (void) e;
  i = 0;
  while (i < MAX_FD)
    {
      if (e->fd_type[i] == FD_GRAPHICAL_SERVER)
	write_on_client(message, i);
      i = i + 1;
    }
  xfree(message);
}

void 	graphic(t_env *client, int fd, char **arg)
{
  t_monitors *monitor;
  t_players  *player;

  (void) arg;
  client->fd_type[fd] = FD_GRAPHICAL_SERVER;
  if ((monitor = get_monitor_from_id(client->monitors, fd)) == NULL)
    create_monitors(client->monitors, fd);
  msz(client, fd, arg);
  sgt(client, fd, arg);
  mct(client, fd, arg);
  tna(client, fd, arg);
  player = client->players->next;
  while (player != client->players)
    {
      pnw(client, player);
      player = player->next;
    }
}
