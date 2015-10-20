/*
** my_linked_list.c for zappy in /Users/junger_m/EPITECH/TEK1/SYSTEME UNIX/PSU_2013_42sh/linked_list
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Fri Jun 19 17:46:47 2015 Maxime JUNGER
** Last update Fri Jul  3 15:22:14 2015 Maxime JUNGER
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <server/parser.h>
#include <server/lib.h>

void		my_show_list(t_teams *list)
{
  t_teams	*tmp;

  tmp = list->next;
  while (tmp != list)
    {
      printf("%s %d\n", tmp->name, tmp->available_slots);
      tmp = tmp->next;
    }
}

int		my_strlen_list(t_teams *list)
{
  t_teams	*tmp;
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

t_teams		*my_creat_teams(t_teams *elem)
{
  elem = xmalloc(sizeof(*elem));
  elem->name = NULL;
  elem->available_slots = -1;
  elem->prev = elem;
  elem->next = elem;
  return (elem);
}

int		my_put_in_list(t_teams *list, char *str)
{
  t_teams	*elem;

  elem = xmalloc(sizeof(*elem));
  elem->name = strdup(str);
  elem->prev = list->prev;
  elem->next = list;
  list->prev->next = elem;
  list->prev = elem;
  return (0);
}

void		my_delete_list(t_teams *list)
{
  if (!list)
    return ;
  list->prev->next = list->next;
  list->next->prev = list->prev;
  xfree(list);
}
