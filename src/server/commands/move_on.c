/*
** move_on.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Tue Jun 23 15:27:05 2015 Maxime JUNGER
** Last update Fri Jul  3 14:51:41 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/commands.h>
#include <server/server.h>

static void	move_up(t_players *pl, t_env *e)
{
  pl->playery -= 1;
  if (pl->playery == -1)
    pl->playery = e->parser->height - 1;
}

static void	move_down(t_players *pl, t_env *e)
{
  pl->playery += 1;
  if (pl->playery == e->parser->height)
    pl->playery = 0;
}

static void	move_left(t_players *pl, t_env *e)
{
  pl->playerx -= 1;
  if (pl->playerx == -1)
    pl->playerx = e->parser->width - 1;
}

static void	move_right(t_players *pl, t_env *e)
{
  pl->playerx += 1;
  if (pl->playerx == e->parser->width)
    pl->playerx = 0;
}

void		move_on(t_env *e, int fd, char **arg)
{
  t_players	*pl;
  char		*str;

  (void)arg;
  if ((pl = get_player_from_id(e->players, fd)) == NULL)
    return ;
  if (pl->orientation == N)
    move_up(pl, e);
  else if (pl->orientation == E)
    move_right(pl, e);
  else if (pl->orientation == S)
    move_down(pl, e);
  else
    move_left(pl, e);
  printf("Move %d orientation = %d| %d %d\n", pl->id, pl->orientation, pl->playerx, pl->playery);
  write_on_client("ok\n", fd);
  asprintf(&str, "ppo %d %d %d %d\n", fd, pl->playerx,
	   pl->playery, pl->orientation);
  send_mess_graphic_client(e, str);
}
