/*
** parser.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/parser
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Fri May  1 14:29:01 2015 Maxime JUNGER
** Last update Sun Jul  5 09:43:35 2015 Alexandre ARRAMON
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <server/parser.h>
#include <server/server.h>
#include <server/socket.h>

static void	init_struct(t_parser *entry)
{
  entry->port = -1;
  entry->width = -1;
  entry->height = -1;
  entry->teams = NULL;
  entry->authorized_clients = -1;
  entry->delay = 100;
  entry->teams = my_creat_teams(entry->teams);
}

static int	get_index_tab(char *opt)
{
  int		i;
  char		**tab;

  i = 0;
  tab = get_function_tab();
  while (tab[i] != NULL)
    {
      if (strcmp(tab[i], opt) == 0)
        {
	  return (i);
        }
      i++;
    }
  return (-1);
}

static int	get_func(t_parser *entry, char **tab, char *opt)
{
  int		i;
  void		(*tabptrfunc[FUNC_NBR + 1])(t_parser *, char *);

  init_tabptr(tabptrfunc);
  i = 0;
  while (tab[i] && tab[i][0] != '-')
    {
      if (get_index_tab(opt) == 3)
        {
	  while (tab[i] && tab[i][0] != '-')
	    {
	      tabptrfunc[3](entry, tab[i]);
	      i++;
	    }
	}
      else if (get_index_tab(opt) == -1)
	xerror("WRONG OPTION\n");
      else
        {
	  tabptrfunc[get_index_tab(opt)](entry, tab[i]);
	  i++;
        }
    }
  return (i);
}

static void	check_struct(t_parser *block)
{
  if (block->port == -1 || block->width == -1 ||
			block->width < 2 || block->width > 40	|| block->height == -1
			|| block->height < 2 || block->height > 40 || block->delay > 500
      || block->authorized_clients == -1 || block->teams == NULL)
    usage_error();
  if (get_number_teams(block->teams) < 2)
    usage_error();
}

void	parse(t_parser *entry, char **av)
{
    int	i;

    init_struct(entry);
    i = 0;
    while (av[i])
    {
        if (av[i][0] == '-' && av[i + 1])
        {
            if (get_func(entry, av + i + 1, av[i]) != 0)
                i += get_func(entry, av + i + 1, av[i]);
            else
	      usage_error();
        }
        else
            i++;
    }
    check_struct(entry);
}
