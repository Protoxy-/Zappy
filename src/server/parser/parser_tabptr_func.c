/*
** tabptr_func.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/parser
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Mon Jun 15 15:47:34 2015 Maxime JUNGER
** Last update Fri Jul  3 15:49:47 2015 Maxime JUNGER
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <server/lib.h>
#include <server/parser.h>
#include <server/server.h>
#include <server/lib.h>

void	authorized_clients(t_parser *block, char *cmd)
{
  my_check_string(cmd);
  block->authorized_clients = atoi(cmd);
  set_all_available_slots(block->teams, block->authorized_clients);
}

void	delay(t_parser *block, char *cmd)
{
  my_check_string(cmd);
  block->delay = atoi(cmd);
}

char	*transform_to_good_teams(char **tab)
{
  int	i;
  char  *newstr;

  i = 0;
  newstr = NULL;
  while (tab[i] && tab[i][0] != '-')
    {
      if (i == 0)
	newstr = strdup(tab[i]);
      else
        {
	  newstr = xrealloc(newstr, sizeof(char)
			    * (strlen(tab[i]) + 1));
	  sprintf(newstr, "%s|%s%c", newstr, tab[i], '\0');
        }
      if (newstr == NULL)
	xerror("ERROR ALLOC");
      i++;
    }
  return (newstr);
}

char	**get_function_tab()
{
  char	**tab;

  tab = my_str_to_wordtab("-p -x -y -n -c -t", ' ');
  return (tab);
}
