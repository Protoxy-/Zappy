/*
** inventaire.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/commands
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Thu Jun 25 11:44:55 2015 Maxime JUNGER
** Last update Fri Jul  3 14:50:05 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>

void		inventory(t_env *e, int fd, char **arg)
{
  t_players	*tmp;
  char		*str;

  (void) arg;
  tmp = get_player_from_id(e->players, fd);
  if (tmp != NULL)
    {
      asprintf(&str, "{nourriture %d, linemate %d, deraumere %d,"
	       " sibur %d, mendiane %d, phiras %d, thystame %d}\n",
	       tmp->inventory->food,
	       tmp->inventory->linemate, tmp->inventory->deraumere,
	       tmp->inventory->sibur, tmp->inventory->mendiane,
	       tmp->inventory->phiras, tmp->inventory->thystame);
      write_on_client(str, fd);
    }
  else
    smg(fd, "Player not found ? Wtf");
}
