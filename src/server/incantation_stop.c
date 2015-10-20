/*
** incantation_stop.c for ZAPPY in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Sat Jun 27 15:31:42 2015 Maxime JUNGER
** Last update Sun Jul  5 20:04:05 2015 Alexandre PAGE
*/

#include <server/socket.h>
#include <server/commands.h>
#include <server/server.h>
#include <server/lib.h>
#include <server/incantation.h>

bool		check_all_there(t_env *e, t_players *before,
				t_players *who_asked)
{
  int		nbr_bef;
  int		nbr_found;
  t_players	*tmp;
  t_players	*tmp2;
  t_players	*on_case;

  nbr_bef = get_number_players(before);
  nbr_found = 0;
  on_case = get_players_on_case(e, who_asked->playerx, who_asked->playery);
  if (get_number_players(on_case) != nbr_bef)
    return (FALSE);
  tmp = before->next;
  while (tmp != before)
    {
      tmp2 = on_case->next;
      while (tmp2 != on_case)
	{
	  if (tmp2->id == tmp->id)
	    nbr_found++;
	  tmp2 = tmp2->next;
	}
      tmp = tmp->next;
    }
  return ((nbr_found == nbr_bef) ? TRUE : FALSE);
}

void	level_up_player(t_env *e, int id)
{
  t_players	*pl;

  pl = get_player_from_id(e->players, id);
  if (pl)
    {
      pl->level += 1;
    }
}

void		set_all_non_elevating(t_env *e, t_players *list,
				      bool can_level_up)
{
  t_players	*tmp;
  char		*str;

  tmp = list->next;
  while (tmp != list)
    {
      tmp->is_elevating = FALSE;
      if (can_level_up)
	{
	  level_up_player(e, tmp->id);
	  asprintf(&str, "niveau actuel : %d\n", tmp->level + 1);
	  write_on_client(str, tmp->id);
	  asprintf(&str, "plv %d %d\n", tmp->id, tmp->level + 1);
	  send_mess_graphic_client(e, str);
	}
      else
	{
	  asprintf(&str, "niveau actuel : %d\n", tmp->level);
	  write_on_client(str, tmp->id);
	  asprintf(&str, "plv %d %d\n", tmp->id, tmp->level);
	  send_mess_graphic_client(e, str);
	}
      tmp = tmp->next;
    }
}

void	update_bct_graphic(t_env *e)
{
  int 	i;

  i = 0;
  while (i < MAX_FD)
    {
      if (e->fd_type[i] == FD_GRAPHICAL_SERVER)
	mct(e, i, NULL);
      i = i + 1;
    }
}

void		incantation_stop(t_env *e, int fd, char **arg,
				 t_incantation *inc)
{
  char		*str;
  int		res;

  (void) fd;
  (void) arg;
  res = 1;
	str = NULL;
  if (inc && inc->players && inc->who_asked)
    if (!check_all_there(e, inc->players, inc->who_asked))
      res = 0;
  if (res == 1)
    set_all_non_elevating(e, inc->players, TRUE);
  else
    set_all_non_elevating(e, inc->players, FALSE);
	printf("INCX ->%d INCY ->%d\n", inc->start_x, inc->start_y);
  asprintf(&str, "pie %d %d %d\n", inc->start_x, inc->start_y, res);
  send_mess_graphic_client(e, str);
  update_bct_graphic(e);
}
