/*
** pdr.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Mon Jun 22 20:32:15 2015 Alexandre PAGE
** Last update Sun Jul  5 13:25:32 2015 Alexandre PAGE
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>

void	take_throw_out_graphical_send(t_players *player, t_map *map, t_env *e)
{
  char	*str;

  asprintf(&str, "pin %d %d %d %d %d %d %d %d %d %d\n", player->id,
	   player->playerx, player->playery, player->inventory->food,
	   player->inventory->linemate, player->inventory->deraumere,
	   player->inventory->sibur, player->inventory->mendiane,
	   player->inventory->phiras, player->inventory->thystame);
  send_mess_graphic_client(e, str);
  asprintf(&str, "bct %d %d %d %d %d %d %d %d %d\n", player->playerx,
	   player->playery, map->food, map->linemate, map->deraumere,
	   map->sibur, map->mendiane, map->phiras, map->thystame);
  send_mess_graphic_client(e, str);
}

void	action_player(t_env *e, t_players *player, char **arg, int fd)
{
  t_map	*map;
  bool	(*map_tabptrfn[NBR_STONE * 2])(t_map *);
  int	token;
  char	*str;

  map = &(e->map[player->playerx][player->playery]);
  map_init_tabptr(map_tabptrfn);
  map_init_tabptr2(map_tabptrfn);
  token = get_token_food(arg[1]);
  if (token == -1)
    write_on_client(KO, fd);
  else
    {
      if (map_tabptrfn[token + NBR_STONE](player->inventory) == TRUE)
	{
	  map_tabptrfn[token](&(e->map[player->playerx][player->playery]));
	  asprintf(&str, "pdr %d\n", player->id);
	  send_mess_graphic_client(e, str);
	  take_throw_out_graphical_send(player, map, e);
	  write_on_client(OK, fd);
	}
      else
	write_on_client(KO, fd);
    }
}

void		pdr(t_env *e, int fd, char **arg)
{
  t_players	*player;

  if (arg[0] && arg[1])
    {
      if ((player = get_player_from_id(e->players, fd)) == NULL)
	write_on_client(KO, fd);
      else
	{
	  action_player(e, player, arg, fd);
	}
    }
  else
    sbp(e, fd, arg);
}
