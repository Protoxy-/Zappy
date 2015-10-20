/*
** sgt.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/commands
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Wed Jun 24 18:35:07 2015 Maxime JUNGER
** Last update Fri Jul  3 15:02:03 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>
#include <server/lib.h>

void	sgt(t_env *e, int fd, char **arg)
{
  char	*str;

  (void)arg;
  asprintf(&str, "sgt %d\n", e->parser->delay);
  write_on_client(str, fd);
  xfree(str);
}

void	sgt_set(t_env *e, int fd, char **arg)
{
  char	*str;

  if (arg[1])
    {
      if (atof(arg[1]) > 0)
	e->parser->delay = atof(arg[1]);
      else
	sbp(e, fd, arg);
      asprintf(&str, "sgt %d\n", e->parser->delay);
      write_on_client(str, fd);
      xfree(str);
    }
  else
    sbp(e, fd, arg);
}
