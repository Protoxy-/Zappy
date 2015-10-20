/*
** ppo.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/commands
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Mon Jun 22 12:22:22 2015 Maxime JUNGER
** Last update Fri Jul  3 15:01:19 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>
#include <server/lib.h>

void	ppop(t_players *player, t_env *e)
{
  char	*str;

  str = NULL;
  if (player)
    {
      asprintf(&str, "ppo %d %d %d %d\n", player->id, player->playerx,
	       player->playery, player->orientation);
      send_mess_graphic_client(e, str);
    }
}

void		ppo(t_env *e, int fd, char **arg)
{
  int		numero_player;
  t_players	*tmp;
  char		*str;

  if (arg[1] && arg[1][0] && arg[1][1])
    {
      numero_player = atoi(arg[1] + 1);
      tmp = get_player_from_id(e->players, numero_player);
      if (tmp != NULL)
	{
	  asprintf(&str, "ppo %d %d %d %d\n", tmp->id, tmp->playerx,
		   tmp->playery, tmp->orientation);
	  write_on_client(str, fd);
	  xfree(str);
	}
      else
	sbp(e, fd, arg);
    }
  else
    sbp(e, fd, arg);
}
