/*
** pbc.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/commands
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Mon Jun 22 10:05:03 2015 Maxime JUNGER
** Last update Sun Jul  5 13:41:49 2015 Alexandre PAGE
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>
#include <server/lib.h>
#include <server/sound.h>
#include <string.h>

void		if_client(t_env *e, int i, int num_joueur, char *message)
{
  t_players	*sender;
  t_players	*listener;
  char		*str;
  int		coming;

  sender = get_player_from_id(e->players, num_joueur);
  if ((listener = get_player_from_id(e->players, i)) != NULL && listener)
    {
      coming = get_sound_coming_case(e, sender, listener);
      if (coming == -1)
	return ;
      asprintf(&str, "message %d,%s\n",
	       coming, message);
      write_on_client(str, i);
      xfree(str);
    }
}

void	write_to_all(t_env *e, int num_joueur, int fd, char *message)
{
  int	i;
  char	*str;

  i = 0;
  while (i < MAX_FD)
    {
      if (e->fd_type[i] == FD_GRAPHICAL_SERVER)
	{
	  asprintf(&str, "pbc %d %s\n", num_joueur, message);
	  write_on_client(str, i);
	  xfree(str);
	}
      else if (e->fd_type[i] == FD_CLIENT)
	{
	  if_client(e, i, num_joueur, message);
	}
      i += (i + 1 == num_joueur) ? 2 : 1;
    }
  write_on_client(OK, fd);
}

char	*concat_all(char **arg)
{
  char	*str;
  int	i;

  i = 2;
  asprintf(&str, "%s", arg[1]);
  while (arg[i])
    {
      asprintf(&str, "%s %s", str, arg[i]);
      i++;
    }
  return (str);
}

void	pbc(t_env *e, int fd, char **arg)
{
  int	num_joueur;
  char	*message;

  (void)fd;
  if (arg && arg[0] && arg[1])
    {
      num_joueur = fd;
      message = concat_all(arg);
      write_to_all(e, num_joueur, fd, message);
    }
  else
    {
      if (get_monitor_from_id(e->monitors, fd))
	sbp(e, fd, arg);
      else
	write_on_client(KO, fd);
    }
}
