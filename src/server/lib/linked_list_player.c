/*
** linked_list_player.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Sun Jun 21 14:31:39 2015 Alexandre PAGE
** Last update Fri Jul  3 22:46:24 2015 Alexandre PAGE
*/

#include <server/server.h>
#include <server/socket.h>
#include <server/lib.h>

int		get_number_players(t_players *list)
{
  int		i;
  t_players	*tmp;

  i = 0;
  tmp = list->next;
  while (tmp != list)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

t_players	*init_player(t_players *elem)
{
  elem = xmalloc(sizeof(*elem));
  elem->id = -1;
  elem->prev = elem;
  elem->next = elem;
  return (elem);
}

int		create_player(t_players *list, t_parser *parser, int id)
{
  t_players	*elem;

  elem = xmalloc(sizeof(*elem));
  elem->prev = list->prev;
  elem->next = list;
  list->prev->next = elem;
  list->prev = elem;
  elem->id = id;
  elem->level = 1;
  elem->team_name = NULL;
  elem->pnw = FALSE;
  elem->is_elevating = FALSE;
  elem->timestamp_health = get_current_time();
  elem->playerxegg = -1;
  elem->playeryegg = -1;
  elem->idegg = -1;
  elem->ghost = FALSE;
  elem->isegg = FALSE;
  generate_position(elem, parser);
  generate_orientation(elem);
  elem->inventory = init_inventory();
	list->playerx = -1;
	list->playery = -1;
  return (0);
}

void		add_player_to_list(t_players *list, t_players *new)
{
  t_players	*elem;

  elem = xmalloc(sizeof(*elem));
  elem->prev = list->prev;
  elem->next = list;
  list->prev->next = elem;
  list->prev = elem;
  elem->id = new->id;
  elem->level = new->level;
  elem->team_name = new->team_name;
  elem->pnw = new->pnw;
  elem->is_elevating = new->is_elevating;
  elem->playerx = new->playerx;
  elem->playery = new->playery;
  elem->orientation = new->orientation;
  elem->inventory = new->inventory;
}

void	delete_player(t_players *list, t_env *e)
{
  if (list)
    {
      if (list->isegg == FALSE)
	{
	  xfree(e->name[list->id]);
	  e->fd_type[list->id] = FD_FREE;
	}
      list->id = -1;
      list->level = -1;
      list->orientation = -1;
      list->playerx = -1;
      list->playery = -1;
      list->prev->next = list->next;
      list->next->prev = list->prev;
      xfree(list->team_name);
      xfree(list);
    }
}

