/*
** see.c for zappy in /home/alexandre/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Wed Jun 24 21:41:05 2015 Alexandre PAGE
** Last update Sun Jul  5 19:51:19 2015 Alexandre ARRAMON
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>
#include <server/lib.h>

void init_ressource(int (*map_tabptrfn[NBR_STONE + 1])())
{
  map_tabptrfn[0] = &get_food;
  map_tabptrfn[1] = &get_linemate;
  map_tabptrfn[2] = &get_deraumere;
  map_tabptrfn[3] = &get_sibur;
  map_tabptrfn[4] = &get_mendiane;
  map_tabptrfn[5] = &get_phiras;
  map_tabptrfn[6] = &get_thystame;
  map_tabptrfn[NBR_STONE] = NULL;
}

static void west(int levelplayer, int fd, t_env *e, t_players *player)
{
  int x;
  int y;
  int j;

  x = (player->playerx - levelplayer) % e->parser->width;
  y = (player->playery + levelplayer) % e->parser->height;
  j = 0;
  while (j < (levelplayer * 2) + 1)
    {
      if (y < 0)
	y = e->parser->height + y;
      print_stone(fd, e, (x + e->parser->width) % e->parser->width,
		  (y + e->parser->height) % e->parser->height);
      y = y - 1;
      j = j + 1;
      if (j < (levelplayer * 2) + 1)
	dprintf(fd, ",");
    }
}

static void make_see(int levelplayer, t_players *player, int fd, t_env *e)
{
  int count;

  count = 0;
  dprintf(fd, "{");
  while (count < levelplayer + 1)
  {
    if (player->orientation == O)
      west(count, fd, e, player);
    else if (player->orientation == N)
      north(count, fd, e, player);
    else if (player->orientation == E)
      east(count, fd, e, player);
    else if (player->orientation == S)
      south(count, fd, e, player);
    count = count + 1;
    if (count < levelplayer + 1 || count == 0)
      dprintf(fd, ",");
  }
  dprintf(fd, "}\n");
}

void		see(t_env *e, int fd, char **arg)
{
  int		levelplayer;
  t_players	*player;

  (void) arg;
  if ((player = get_player_from_id(e->players, fd)) == NULL)
    smg(fd, "Player not found ? wtf");
  else
    {
      levelplayer = player->level;
      make_see(levelplayer, player, fd, e);
    }
}
