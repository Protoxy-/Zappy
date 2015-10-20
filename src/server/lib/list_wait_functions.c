/*
** list_wait_functions.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/lib
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Tue Jun 23 16:15:49 2015 Maxime JUNGER
** Last update Sat Jul  4 14:11:44 2015 Maxime JUNGER
*/

#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <server/parser.h>
#include <server/lib.h>
#include <server/list_wait_functions.h>

t_wait	*my_creat_wait_list(t_wait *elem)
{
  elem = xmalloc(sizeof(*elem));
  elem->arg = NULL;
  elem->fd = -1;
  elem->fct = NULL;
  elem->time_when_call = -1;
  elem->numerator = -1;
  elem->next = elem;
  elem->is_incantation = FALSE;
  elem->prev = elem;
  return (elem);
}

t_wait		*get_function_to_run(t_wait *list, t_env *e)
{
  t_wait	*tmp;
  double	delay;

  tmp = list->next;
  while (tmp != list)
    {
      if (str_list_queue(e->actionQueue) >= 1)
        {
	  delay = (double)tmp->numerator / (double)e->parser->delay;
	  if (get_current_time() >
	      (tmp->time_when_call + convert_seconde_mili(delay)))
	    return (tmp);
	  tmp = tmp->next;
	}
      else
	return (NULL);
    }
  return (NULL);
}

void		put_in_wait_list(t_wait *list, t_wait *new)
{
  t_wait	*elem;

  elem = xmalloc(sizeof(*elem));
  elem->arg = new->arg;
  elem->fd = new->fd;
  elem->fct = new->fct;
  elem->time_when_call = new->time_when_call;
  elem->numerator = new->numerator;
  elem->incant = new->incant;
  elem->is_incantation = new->is_incantation;
  elem->prev = list->prev;
  elem->next = list;
  list->prev->next = elem;
  list->prev = elem;
}

int		nbr_waiting_functions(t_wait *list)
{
  t_wait	*tmp;
  int		i;

  i = 0;
  tmp = list->next;
  while (tmp != list)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

void		delete_func(t_wait *list)
{
  if (!list)
    return ;
  list->prev->next = list->next;
  list->next->prev = list->prev;
  xfree(list);
}
