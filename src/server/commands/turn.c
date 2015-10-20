/*
** turn.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Tue Jun 23 16:08:24 2015 Maxime JUNGER
** Last update Fri Jul  3 15:03:48 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>

void			turn_left(t_env *e, int fd, char **arg)
{
  t_players		*pl;
  enum direction	new;
  char			*str;

  (void)arg;
  if ((pl = get_player_from_id(e->players, fd)) == NULL)
    return ;
  if (pl->orientation == N)
    new = O;
  else if (pl->orientation == O)
    new = S;
  else if (pl->orientation == S)
    new = E;
  else
    new = N;
  pl->orientation = new;
  write_on_client(OK, fd);
  asprintf(&str, "ppo %d %d %d %d\n", fd, pl->playerx,
	   pl->playery, pl->orientation);
  send_mess_graphic_client(e, str);
}

void			turn_right(t_env *e, int fd, char **arg)
{
  t_players		*pl;
  enum direction	new;
  char			*str;

  (void)arg;
  if ((pl = get_player_from_id(e->players, fd)) == NULL)
    return ;
  if (pl->orientation == N)
    new = E;
  else if (pl->orientation == E)
    new = S;
  else if (pl->orientation == S)
    new = O;
  else
    new = N;
  pl->orientation = new;
  write_on_client(OK, fd);
  asprintf(&str, "ppo %d %d %d %d\n", fd, pl->playerx,
	   pl->playery, pl->orientation);
  send_mess_graphic_client(e, str);
}
