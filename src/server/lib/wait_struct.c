/*
** wait_struct.c for zazppy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/lib
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Wed Jun 24 14:17:47 2015 Maxime JUNGER
** Last update Sun Jul  5 13:50:00 2015 Alexandre PAGE
*/

#include <sys/time.h>
#include <server/lib.h>
#include <server/list_wait_functions.h>

t_wait		*new_wait_struct(int fd, char **arg, void (*fct)(),
				 int wait_time)
{
  t_wait	*new;

  new = xmalloc(sizeof(*new));
  new->fd = fd;
  new->arg = arg;
  new->fct = fct;
  new->numerator = wait_time;
  new->time_when_call = get_current_time();
  new->is_incantation = FALSE;
  return (new);
}

void	set_incantate_struct(t_wait *w, t_incantation *inc)
{
  w->is_incantation = TRUE;
  w->incant = inc;
}
