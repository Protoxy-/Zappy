/*
** plv.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/commands
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Mon Jun 22 14:02:35 2015 Maxime JUNGER
** Last update Fri Jul  3 15:00:02 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>
#include <server/lib.h>

void		plv(t_env *e, int fd, char **arg)
{
  int		numero_player;
  t_players	*tmp;
  char		*str;

  if (arg && arg[1] && arg[1][0] && arg[1][1])
    {
      numero_player = atoi(arg[1] + 1);
      tmp = get_player_from_id(e->players, numero_player);
      if (tmp != NULL)
	{
	  asprintf(&str, "ppo %d %d\n", tmp->id, tmp->level);
	  write_on_client(str, fd);
	  xfree(str);
	}
      else
	sbp(e, fd, arg);
    }
  else
    sbp(e, fd, arg);
}
