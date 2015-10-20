/*
** pex.c for zappy in /home/alex/rendu/zappy/src/server
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Mon Jun 22 17:48:37 2015 Alexandre PAGE
** Last update Sun Jul  5 13:25:49 2015 Alexandre PAGE
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>

static void	check_position(t_players *player, t_parser *parser)
{
  if (player->playerx >= parser->width)
    player->playerx = 0;
  else if (player->playerx < 0)
    player->playerx = parser->width;
  if (player->playery >= parser->height)
    player->playery = 0;
  else if (player->playery < 0)
    player->playery = parser->height;
}

static void	expulse(t_players *player, int orientation,
			int fd, t_parser *parser)
{
  if (orientation == N)
    player->playery -= 1;
  else if (orientation == E)
    player->playerx += 1;
  else if (orientation == S)
    player->playery += 1;
  else if (orientation == O)
    player->playerx -= 1;
  else
    write_on_client(KO, fd);
  check_position(player, parser);
}

static void	send_ppo(t_players *players, t_env *e)
{
  t_players	*player;

  player = players->next;
  while (player != players)
    {
      ppop(player, e);
      player = player->next;
    }
}

static void ok_or_ko(int i, int fd, t_players *player, t_env *e)
{
  char *send;

  send = NULL;
  if (i != 0)
    write_on_client(OK, fd);
  else
    write_on_client(KO, fd);
  asprintf(&send, "pex %d\n", player->id);
  send_ppo(e->players, e);
  send_mess_graphic_client(e, send);
}

void		pex(t_env *e, int fd, char **arg)
{
  t_players	*player;
  t_players	*tmp;
  int   i;

  i = 0;
  (void) arg;
  if ((player = get_player_from_id(e->players, fd)) == NULL)
    write_on_client(KO, fd);
  else
    {
      tmp = e->players->next;
      while (tmp != e->players)
	{
    	  if (player->playerx == tmp->playerx
	      && tmp->playery == player->playery
    	      && player->id != tmp->id)
	    {
	      i = i + 1;
	      expulse(tmp, player->orientation, fd, e->parser);
	    }
    	  tmp = tmp->next;
	}
      ok_or_ko(i, fd, player, e);
    }
}
