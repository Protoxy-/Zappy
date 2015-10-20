/*
** welcome.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Thu Jun 18 22:45:59 2015 Alexandre PAGE
** Last update Fri Jul  3 15:55:58 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/parser.h>
#include <server/lib.h>
#include <server/commands.h>

void	communicate_coordonate(t_parser *parser, int fd)
{
  char		*str;

  str = NULL;
  asprintf(&str, "%d %d\n", parser->width, parser->height);
  write_on_client(str, fd);
  xfree(str);
}

static void	setting_up_player(t_players *tmp, t_env *e, char *str)
{
  tmp->team_name = strdup(str);
  tmp->pnw = TRUE;
  tmp->ghost = FALSE;
  communicate_coordonate(e->parser, tmp->id);
  pnw(e, tmp);
}

static void print_available_slot(int n, int fd)
{
  char *str;

  str = NULL;
  asprintf(&str, "%d\n", n);
  write_on_client(str, fd);
  xfree(str);
}

void		teamname(t_env *e, int fd, char **arg)
{
  t_players	*tmp;
  t_players	*playerghost;
  int		n;

  if ((n = get_available_slots(e->parser->teams, arg[0])) >= 1)
    {
      change_available_slots(e->parser->teams, arg[0], n - 1);
      n = get_available_slots(e->parser->teams, arg[0]);
      print_available_slot(n, fd);
      playerghost = get_ghost(e->players, arg[0]);
      if (playerghost == NULL)
	{
	  printf("Creation d'un joueur\n");
	  create_player(e->players, e->parser, fd);
	  if ((tmp = get_player_from_id(e->players, fd)) != NULL)
	    setting_up_player(tmp, e, arg[0]);
	}
      else
	remplacing_player(playerghost, fd, e);
    }
  else
    write_on_client(KO, fd);
}
