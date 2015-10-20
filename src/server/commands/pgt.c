/*
** pgt.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Tue Jun 23 10:41:05 2015 Alexandre PAGE
** Last update Sun Jul  5 14:00:50 2015 Alexandre PAGE
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>
#include <common.h>
#include <server/lib.h>

static void generate_elem(t_env *e, int token, t_players *player, t_map *map)
{
  bool      (*map_tabptrfn[NBR_STONE + 1])(t_map *);
  int x;
  int y;
  char	*str;
  int 	i;

  map_init_tabptr(map_tabptrfn);
  x = rand() % e->parser->width;
  y = rand() % e->parser->height;
  map_tabptrfn[token](&(e->map[x][y]));
  asprintf(&str, "bct %d %d", x, y);
  i = 0;
  while (i < MAX_FD)
    {
      if (e->fd_type[i] == FD_GRAPHICAL_SERVER)
	bct(e, i, my_str_to_wordtab(str, ' '));
      i = i + 1;
    }
  take_throw_out_graphical_send(player, map, e);
}

static void	pgt_next(t_players *player, int fd, t_env *e, char **arg)
{
  int		token;
  char  	*str;
  bool		(*map_tabptrfn[(NBR_STONE * 2) + 1])(t_map *);
  t_map 	*map;

  token = get_token_food(arg[1]);
  if (token != -1)
    {
      map_init_tabptr(map_tabptrfn);
      map_init_tabptr2(map_tabptrfn);
      map = &(e->map[player->playerx][player->playery]);
      if (map_tabptrfn[token + NBR_STONE](&(e->map[player->playerx]
					    [player->playery])) == TRUE)
	{
	  map_tabptrfn[token](player->inventory);
	  asprintf(&str, "pgt %d %d\n", player->id, token);
	  send_mess_graphic_client(e, str);
	  generate_elem(e, token, player, map);
	  write_on_client(OK, fd);
	}
      else
	write_on_client(KO, fd);
    }
  else
    sbp(e, fd, arg);
}

void		pgt(t_env *client, int fd, char **arg)
{
  t_players 	*player;

  if (arg[0] && arg[1])
    {
      if ((player = get_player_from_id(client->players, fd)) == NULL)
	write_on_client(KO, fd);
      else
	pgt_next(player, fd, client, arg);
    }
  else
    sbp(client, fd, arg);
}
