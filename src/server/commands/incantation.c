/*
** incantation.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/commands
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Thu Jun 25 10:58:20 2015 Maxime JUNGER
** Last update Fri Jul  3 14:48:57 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/commands.h>
#include <server/server.h>
#include <server/lib.h>
#include <server/incantation.h>

t_players	*get_players_on_case(t_env *e, int pos_x, int pos_y)
{
  t_players	*on_map;
  t_players	*tmp;

  on_map = NULL;
  on_map = init_player(on_map);
  tmp = e->players->next;
  while (tmp != e->players)
    {
      if (tmp->playerx == pos_x && tmp->playery == pos_y)
	{
	  add_player_to_list(on_map, tmp);
	}
      tmp = tmp->next;
    }
  return (on_map);
}

void		set_all_elevating(t_players *list)
{
  t_players	*tmp;

  tmp = list->next;
  while (tmp != list)
    {
      tmp->is_elevating = TRUE;
      tmp = tmp->next;
    }
}

bool		is_one_elevating(t_players *list)
{
  t_players	*tmp;

  tmp = list->next;
  while (tmp != list)
    {
      if (tmp->is_elevating)
	return (TRUE);
      tmp = tmp->next;
    }
  return (FALSE);
}

bool		check_if_all_is_good(t_map map, t_players *list, int level)
{
  int		(*fct[8])(t_map *, t_players *);
  t_players	*tmp;

  fct[0] = &level_1;
  fct[1] = &level_2;
  fct[2] = &level_3;
  fct[3] = &level_4;
  fct[4] = &level_5;
  fct[5] = &level_6;
  fct[6] = &level_7;
  fct[7] = NULL;
  tmp = list->next;
  while (tmp != list)
    {
      if (tmp->level != level)
	return (FALSE);
      tmp = tmp->next;
    }
  if (!fct[level - 1](&map, list))
    return (FALSE);
  return (TRUE);
}

t_incantation	*incantation_start(t_env *e, int fd, char **arg)
{
  t_players	*player;
  t_players	*list;
  t_incantation	*res;

  (void)arg;
  if ((player = get_player_from_id(e->players, fd)) == NULL)
    return (NULL);
  list = get_players_on_case(e, player->playerx, player->playery);
  if (is_one_elevating(list)
      || !check_if_all_is_good(e->map[player->playerx][player->playery],
			       list, player->level))
    {
      write_to_all_players(KO, list);
      return (NULL);
    }
  set_all_elevating(list);
  res = xmalloc(sizeof(res));
	init_res(res);
	res->players = list;
  res->who_asked = player;
  res->start_x = player->playerx;
  res->start_y = player->playery;
  write_to_all_players("elevation en cours\n", list);
  send_mess_to_graphic(e, res);
  return (res);
}
