/*
** see_func.c for zappy in /home/alexandre/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Thu Jul  2 20:13:41 2015 Alexandre PAGE
** Last update Sun Jul  5 19:14:40 2015 Alexandre ARRAMON
*/

#include <server/server.h>
#include <server/socket.h>
#include <server/lib.h>
#include <server/commands.h>

void print_stone(int fd, t_env *e, int x, int y)
{
  int j;
  int     (*map_tabptrfn[NBR_STONE + 1])(t_map *);
  int nbr_stone;
  static char     *stone[] = {"nourriture", "linemate", "deraumere",
			      "sibur", "mendiane", "phiras", "thystame", NULL};
  int nbr_player;

  init_ressource(map_tabptrfn);
  j = 0;
  while (j < NBR_STONE)
    {
      nbr_stone = map_tabptrfn[j](&(e->map[x][y]));
      while (nbr_stone > 0)
	{
	  dprintf(fd, " %s", stone[j]);
	  nbr_stone--;
	}
      j = j + 1;
    }
  nbr_player = get_player(e->players, x, y);
  while (nbr_player > 0)
    {
      dprintf(fd, " joueur");
      nbr_player--;
    }
}

void north(int levelplayer, int fd, t_env *e, t_players *player)
{
  int x;
  int y;
  int j;

  x = (player->playerx - levelplayer) % e->parser->width;
  y = (player->playery - levelplayer) % e->parser->height;
  j = 0;
  while (j < (levelplayer * 2) + 1)
    {
      print_stone(fd, e, (x + e->parser->width) % e->parser->width,
		  (y + e->parser->height) % e->parser->height);
      x = x + 1;
      j = j + 1;
      if (j < (levelplayer * 2) + 1)
	dprintf(fd, ",");
    }
}

void east(int levelplayer, int fd, t_env *e, t_players *player)
{
  int x;
  int y;
  int j;

  x = (player->playerx + levelplayer) % e->parser->width;
  y = (player->playery - levelplayer) % e->parser->height;
  j = 0;
  while (j < (levelplayer * 2) + 1)
    {
      print_stone(fd, e, (x + e->parser->width) % e->parser->width,
		  (y + e->parser->height) % e->parser->height);
      y = y + 1;
      j = j + 1;
      if (j < (levelplayer * 2) + 1)
	dprintf(fd, ",");
    }
}

void south(int levelplayer, int fd, t_env *e, t_players *player)
{
  int x;
  int y;
  int j;

  x = (player->playerx + levelplayer) % e->parser->width;
  y = (player->playery + levelplayer) % e->parser->height;
  j = 0;
  while (j < (levelplayer * 2) + 1)
    {
      if (x < 0)
	x = e->parser->width + x;
      print_stone(fd, e, (x + e->parser->width) % e->parser->width,
		  (y + e->parser->height) % e->parser->height);
      x = x - 1;
      j = j + 1;
      if (j < (levelplayer * 2) + 1)
	dprintf(fd, ",");
    }
}
