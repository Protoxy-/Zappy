/*
** main.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Thu Jun 18 18:01:29 2015 Alexandre PAGE
** Last update Sun Jul  5 16:23:36 2015 Alexandre ARRAMON
*/

#include <server/socket.h>
#include <server/lib.h>
#include <server/parser.h>
#include <server/server.h>
#include <server/list_wait_functions.h>
#include <server/commands.h>
#include <signal.h>

int		str_list_queue(t_wait *wait)
{
  t_wait	*tmp;
  int		i;

  i = 0;
  tmp = wait->next;
  while (wait != tmp)
    {
      tmp = tmp->next;
      i++;
    }
  return i;
}

void		extracted_function(t_env *e)
{
  t_wait	*to_do;

  while ((to_do = get_function_to_run(e->actionQueue, e)) != NULL)
    {
      if (!to_do->fct && to_do->is_incantation == TRUE)
	{
	  incantation_stop(e, to_do->fd, to_do->arg, to_do->incant);
	  if (to_do)
	    delete_func(to_do);
	}
      else if (to_do->fct)
	{
	  to_do->fct(e, to_do->fd, to_do->arg);
	  if (to_do)
	    {
	      delete_func(to_do);
	      if (to_do->fct != &pfk)
		free_str_to_wordtab((void **)to_do->arg);
	    }
	}
    }
}

static void	check_client(fd_set fd_read, fd_set fd_write,
			     t_env *e, void (*tabptrfn[])())
{
  int		i;

  i = 0;
  while (i < MAX_FD)
    {
      if (FD_ISSET(i, &fd_read))
        e->fct_read[i](e, i, tabptrfn);
      if (FD_ISSET(i, &fd_write))
	{
	  e->fct_write[i](e, i);
	  if (e->buf[i])
	    free(e->buf[i]);
	  e->buf[i] = NULL;
	}
      i = i + 1;
    }
  extracted_function(e);
  decrease_health(e->players, e->parser);
  check_death_player(e->players, e);
  check_win(e);
}

static void	init_main_baby(t_env *e, struct timeval *tv,
			       t_parser *parser, char **av)
{
  e->actionQueue = NULL;
  tv->tv_sec = 0;
  tv->tv_usec = 1;
  parse(parser, av);
  e->parser = parser;
}

int			main(int ac, char **av)
{
  t_env			e;
  int			fd_max;
  fd_set		fd_read;
  fd_set		fd_write;
  struct timeval	tv;
  void			(*tabptrfn[NBR_FUNC + 1])(t_env *, int, char **);
  t_parser		parser;

  if (ac == 1)
    usage_error();
  init_main_baby(&e, &tv, &parser, av);
	signal(SIGINT, signal_handler);
  initab(tabptrfn);
  init_serv(&e, init_map(e.parser->height, e.parser->width), e.parser->port);
  e.actionQueue = my_creat_wait_list(e.actionQueue);
  e.monitors = init_monitors(e.monitors);
	g_data = e.players;
  while (1)
    {
      FD_ZERO(&fd_read);
      FD_ZERO(&fd_write);
      fd_max = browse_set_client(&e, &fd_read, &fd_write);
      if (select(fd_max + 1, &fd_read, &fd_write, NULL, &tv) == -1)
	perror("select");
      check_client(fd_read, fd_write, &e, tabptrfn);
    }
  return (0);
}
