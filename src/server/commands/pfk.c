/*
** pfk.c for zappy in /home/alexandre/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Fri Jun 26 09:26:40 2015 Alexandre PAGE
** Last update Fri Jul  3 14:56:50 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>
#include <server/lib.h>
#include <server/list_wait_functions.h>

void		pfkserver(t_env *e, int fd)
{
  char		*str;
  t_players	*player;
  t_players	*players;

  players = e->players;
  if ((player = get_player_from_id(players, fd)) != NULL)
    {
      asprintf(&str, "pfk %d\n", player->id);
      send_mess_graphic_client(e, str);
    }
  else
    smg(fd, KO);
}

void		pfk(t_env *e, int fd, char **arg)
{
  t_players	*player;
  char		*str;
  static int	count = MAX_FD + 1;

  (void) arg;
  if ((player = get_player_from_id(e->players, fd)) != NULL)
    {
      asprintf(&str, "enw %d %d %d %d\n", count, player->id,
	       player->playerx, player->playery);
      player->idegg = count;
      player->playerxegg = player->playerx;
      player->playeryegg = player->playery;
      count++;
      send_mess_graphic_client(e, str);
      write_on_client(OK, fd);
      put_in_wait_list(e->actionQueue,
		       new_wait_struct(fd, arg, &eht, get_wait_time(21)));
    }
  else
    smg(fd, KO);
}
