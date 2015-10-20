/*
** command_nbr.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/commands
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Wed Jun 24 18:48:11 2015 Maxime JUNGER
** Last update Fri Jul  3 14:46:56 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>

void		connect_nbr(t_env *e, int fd, char **arg)
{
  t_players	*pl;
  int		result;
  char		*str;

  (void)arg;
  pl = get_player_from_id(e->players, fd);
  result = get_available_slots(e->parser->teams, pl->team_name);
  asprintf(&str, "%d\n", result);
  write_on_client(str, fd);
}
