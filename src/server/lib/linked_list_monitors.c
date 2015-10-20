/*
** linked_list_monitors.c for zappy in /home/alexandre/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Mon Jun 29 14:36:45 2015 Alexandre PAGE
** Last update Fri Jul  3 15:18:30 2015 Maxime JUNGER
*/

#include <server/server.h>
#include <server/socket.h>
#include <server/lib.h>

t_monitors	*init_monitors(t_monitors *elem)
{
  elem = xmalloc(sizeof(*elem));
  elem->id = -1;
  elem->prev = elem;
  elem->next = elem;
  return (elem);
}

int		create_monitors(t_monitors *list, int id)
{
  t_monitors	*elem;

  elem = xmalloc(sizeof(*elem));
  elem->id = id;
  elem->prev = list->prev;
  elem->next = list;
  list->prev->next = elem;
  list->prev = elem;
  return (0);
}

t_monitors	*get_monitor_from_id(t_monitors *monitors, int id)
{
  t_monitors	*monitor;

  monitor = monitors->next;
  while (monitor != monitors)
    {
      if (monitor->id == id)
	return (monitor);
      monitor = monitor->next;
    }
  return (NULL);
}

void	delete_monitor(t_monitors *list)
{
  if (list)
  {
    list->id = -1;
    list->prev->next = list->next;
    list->next->prev = list->prev;
    xfree(list);
  }
}
