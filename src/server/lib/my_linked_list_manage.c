/*
** my_linked_list_manage.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/lib
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Fri Jun 19 18:10:44 2015 Maxime JUNGER
** Last update Fri Jul  3 15:23:19 2015 Maxime JUNGER
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <server/parser.h>

void		set_all_available_slots(t_teams *list, int nb)
{
  t_teams	*tmp;

  tmp = list->next;
  while (tmp != list)
    {
      tmp->available_slots = nb;
      tmp = tmp->next;
    }
}

void		change_available_slots(t_teams *list, char *team, int nb)
{
  t_teams	*tmp;

  tmp = list->next;
  while (tmp != list)
    {
      if (strcmp(team, tmp->name) == 0)
	tmp->available_slots = nb;
      tmp = tmp->next;
    }
}

int		get_available_slots(t_teams *list, char *name)
{
  t_teams	*tmp;

  tmp = list->next;
  while (tmp != list)
    {
      if (strcmp(name, tmp->name) == 0)
	return (tmp->available_slots);
      tmp = tmp->next;
    }
  return (-1);
}

int		get_number_teams(t_teams *list)
{
  int		i;
  t_teams	*tmp;

  i = 0;
  tmp = list->next;
  while (tmp != list)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

bool		check_if_team_exist(t_teams *list, char *name)
{
  bool		b;
  t_teams	*tmp;

  b = FALSE;
  tmp = list->next;
  while (tmp != list)
    {
      if (strcmp(name, tmp->name) == 0)
	b = TRUE;
      tmp = tmp->next;
    }
  return (b);
}
