/*
** player.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Mon Jun 22 09:27:23 2015 Alexandre PAGE
** Last update Fri Jul  3 15:37:12 2015 Maxime JUNGER
*/

# include <server/server.h>
# include <server/socket.h>
# include <server/parser.h>
# include <server/lib.h>

t_inventory	*init_inventory()
{
  t_inventory	*inventory;

  inventory = xmalloc(sizeof(*inventory));
  inventory->food = 10;
  inventory->linemate = 0;
  inventory->deraumere = 0;
  inventory->sibur = 0;
  inventory->mendiane = 0;
  inventory->phiras = 0;
  inventory->thystame = 0;
  return (inventory);
}

static bool	is_already_busy(int x, int y, t_players *player)
{
  bool		is_busy;
  t_players	*tmp;

  if (x == -1)
    return (TRUE);
  tmp = player->next;
  is_busy = FALSE;
  while (tmp != player)
    {
      if (tmp->id != player->id && tmp->playerx == x && tmp->playery == y)
	is_busy = TRUE;
      tmp = tmp->next;
    }
  return (is_busy);
}

void	generate_position(t_players *player, t_parser *parser)
{
  int	x;
  int	y;
  int	map_height;
  int	map_width;

  x = -1;
  y = -1;
  map_width = parser->width;
  map_height = parser->height;
  srand((unsigned int)time(NULL));
  while (is_already_busy(x, y, player) == TRUE)
    {
      x = rand() % map_width;
      y = rand() % map_height;
    }
  player->playerx = x;
  player->playery = y;
}

void	generate_orientation(t_players *player)
{
  srand((unsigned int)time(NULL));
  player->orientation = (rand() % 3) + 1;
}

t_players	*get_player_from_id(t_players *players, int fd)
{
  t_players	*tmp;

  tmp = players->next;
  while (tmp != players)
    {
      if (tmp->id == fd)
	return (tmp);
      else
	tmp = tmp->next;
    }
  return (NULL);
}
