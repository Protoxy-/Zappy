/*
** incantation_messages.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Fri Jul  3 12:28:29 2015 Maxime JUNGER
** Last update Sun Jul  5 19:57:31 2015 Alexandre PAGE
*/

#include <server/socket.h>
#include <server/commands.h>
#include <server/server.h>
#include <server/lib.h>
#include <server/incantation.h>

void		send_mess_to_graphic(t_env *e, t_incantation *inc)
{
  char		*str;
  t_players	*tmp;

  asprintf(&str, "pic %d %d %d", inc->start_x, inc->start_y,
	   inc->who_asked->level);
  tmp = inc->players->next;
  while (tmp != inc->players)
    {
      asprintf(&str, "%s %d", str, tmp->id);
      tmp = tmp->next;
    }
  asprintf(&str, "%s\n", str);
  send_mess_graphic_client(e, str);
}

void		write_to_all_players(char *str, t_players *list)
{
  t_players	*tmp;

  tmp = list->next;
  while (tmp != list)
    {
      write_on_client(str, tmp->id);
      tmp = tmp->next;
    }
}

void	init_res(t_incantation *res)
{
  res->players = NULL;
  res->who_asked = NULL;
  res->start_x = -1;
  res->start_y = -1;
}
