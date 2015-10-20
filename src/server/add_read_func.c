/*
** add_read_func.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Tue Jun 23 09:57:49 2015 Alexandre PAGE
** Last update Fri Jul  3 14:45:32 2015 Maxime JUNGER
*/

#include <server/server.h>
#include <server/socket.h>
#include <server/commands.h>
#include <server/lib.h>
#include <server/list_wait_functions.h>

void		client_read_next(t_env *e, int fd, char buf[], char **str)
{
  t_players	*player;

  player = get_player_from_id(e->players, fd);
  if (check_if_team_exist(e->parser->teams, buf) == TRUE)
    {
      if (player && player->pnw == FALSE)
	teamname(e, fd, str);
      else if (!player)
	teamname(e, fd, str);
      else
	dprintf(fd, UNKNOWN_COMMAND);
    }
  else if (player && player->pnw == FALSE)
    dprintf(fd, UNKNOWN_TEAM);
  else
    dprintf(fd, UNKNOWN_COMMAND);
}

void		put_func_in_wait(t_env *e, int fd, char **str,
				 void (*tabptrfn[])())
{
  int		token;
  t_players	*player;
  t_wait	*tmp;
  t_incantation	*inc;

  player = get_player_from_id(e->players, fd);
  if (((token = get_token(str[0])) != -1 && player && player->pnw == TRUE))
    {
      if (token == 10)
	pfkserver(e, fd);
      if (strcmp(str[0], "incantation") == 0)
	{
	  tmp = new_wait_struct(fd, str, NULL, 300);
	  if ((inc = incantation_start(e, fd, str)) != NULL)
	    {
	      set_incantate_struct(tmp, inc);
	      put_in_wait_list(e->actionQueue, tmp);
	    }
	}
      else
	put_in_wait_list(e->actionQueue,
			 new_wait_struct(fd, str, tabptrfn[token],
					 get_wait_time(token)));
    }
}

void	else_monitor(t_env *e, int fd, char **str)
{
  int	token;
  void	(*tabptrfnmonitor[10])(t_env *, int, char **arg);

  init_tab_monitor(tabptrfnmonitor);
  if ((token = get_token_serv(str[0])) != -1)
    (*tabptrfnmonitor[token])(e, fd, str);
  else
    dprintf(fd, UNKNOWN_COMMAND);
}

void		client_choose_func(t_env *e, int fd, char *buf,
				   void (*tabptrfn[])())
{
  int		token;
  char		**str;
  t_players	*player;
  t_monitors	*monitor;

  player = get_player_from_id(e->players, fd);
  monitor = get_monitor_from_id(e->monitors, fd);
  str = my_str_to_wordtab(buf, ' ');
  if (!strncmp("GRAPHIC", buf, 7) && !player)
    graphic(e, fd, str);
  else if (str[0])
    {
      if (((token = get_token(str[0])) != -1 && player && player->pnw == TRUE))
	put_func_in_wait(e, fd, str, tabptrfn);
      else if (monitor)
	else_monitor(e, fd, str);
      else
	client_read_next(e, fd, buf, str);
    }
}
