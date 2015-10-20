/*
** parser_tabptr.c for tabpre in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/parser
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Mon Jun 15 15:06:19 2015 Maxime JUNGER
** Last update Fri Jul  3 19:55:58 2015 Maxime JUNGER
*/

#include <stdio.h>
#include <stdlib.h>
#include <server/parser.h>
#include <server/lib.h>

static void	port(t_parser *block, char *cmd)
{
  my_check_string(cmd);
  block->port = atoi(cmd);
}

static void	map_width(t_parser *block, char *cmd)
{
  my_check_string(cmd);
  block->width = atoi(cmd);
}

static void	map_height(t_parser *block, char *cmd)
{
  my_check_string(cmd);
  block->height = atoi(cmd);
}

static void	fill_teams(t_parser *block, char *cmd)
{
  t_teams	*tmp;

  tmp = block->teams->next;
  my_check_string(cmd);
  if (strstr(cmd, ",") != NULL)
    xexit(-1, "Wrong team name\n");
  if (!check_if_team_exist(block->teams, cmd))
    my_put_in_list(block->teams, cmd);
  if (block->authorized_clients != -1)
    {
      while (tmp != block->teams)
	{
	  tmp->available_slots = block->authorized_clients;
	  tmp = tmp->next;
	}
    }
}

void	init_tabptr(void (*tabptrfunc[])())
{
  tabptrfunc[0] = &port;
  tabptrfunc[1] = &map_width;
  tabptrfunc[2] = &map_height;
  tabptrfunc[3] = &fill_teams;
  tabptrfunc[4] = &authorized_clients;
  tabptrfunc[5] = &delay;
  tabptrfunc[FUNC_NBR] = NULL;
}
