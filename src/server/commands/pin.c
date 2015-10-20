/*
** pin.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/commands
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Mon Jun 22 15:43:57 2015 Maxime JUNGER
** Last update Fri Jul  3 14:59:37 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>

void		pin(t_env *e, int fd, char **arg)
{
  int		numero_player;
  t_players	*tmp;
  char		*str;

  if (arg[1])
    {
      numero_player = atoi(arg[1]);
      tmp = get_player_from_id(e->players, numero_player);
      if (tmp != NULL)
	{
	  asprintf(&str, "pin %d %d %d %d %d %d %d %d %d %d\n", tmp->id,
		   tmp->playerx, tmp->playery, tmp->inventory->food,
		   tmp->inventory->linemate, tmp->inventory->deraumere,
		   tmp->inventory->sibur, tmp->inventory->mendiane,
		   tmp->inventory->phiras, tmp->inventory->thystame);
	  write_on_client(str, fd);
	}
      else
	sbp(e, fd, arg);
    }
  else
    sbp(e, fd, arg);
}
