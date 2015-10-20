/*
** init.c for zappy in /home/alex/rendu/zappy/src/server/map
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Thu Jun 18 15:22:31 2015 Alexandre PAGE
** Last update Sun Jul  5 20:06:11 2015 Alexandre PAGE
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/lib.h>

static t_map**	create_map(int height, int width)
{
  int		x;
  t_map 	**map;

  map = xmalloc(sizeof(t_map*) * width);
  x = 0;
  while (x < width)
    {
      map[x] = xmalloc(sizeof(t_map) * height);
      x = x + 1;
    }
  return (map);
}

static void 	fill_map(t_map **map, int height, int width)
{
  int x;
  int y;

  x = 0;
  while (x < width)
    {
      y = 0;
      while (y < height)
	{
	  map[x][y].food = 0;
	  map[x][y].linemate = 0;
	  map[x][y].deraumere = 0;
	  map[x][y].sibur = 0;
	  map[x][y].mendiane = 0;
	  map[x][y].phiras = 0;
	  map[x][y].thystame = 0;
	  y = y + 1;
	}
      x = x + 1;
    }
}

static int	*repartition_food(int height, int width)
{
  int		*coef;

  coef = xmalloc(sizeof(coef) * 8);
  coef[0] = (width * height);
  coef[1] = (width * height) / 20;
  coef[2] = (width * height) / 8;
  coef[3] = (width * height) / 8;
  coef[4] = (width * height) / 8;
  coef[5] = (width * height) / 8;
  coef[6] = 5;
  coef[7] = 0;
  return (coef);
}

static void		generate_stone(t_map **map, int height, int width)
{
  int			random_height;
  int			random_width;
  int			*limit;
  int			i;
  int			j;
  bool			(*map_tabptrfn[NBR_STONE + 1])(t_map *);
  static const char	*stone[] = {"Nourriture", "Linemate", "Deraumere",
				    "Sibur", "Mendiane", "Phiras", "Thystame",
				    NULL};

  map_init_tabptr(map_tabptrfn);
  i = 0;
  limit = repartition_food(height, width);
  while (stone[i])
    {
      j = 0;
      while (j < limit[i])
	{
	  random_height = rand() % height;
	  random_width = rand() % width;
	  map_tabptrfn[i](&map[random_width][random_height]);
	  j = j + 1;
	}
      i = i + 1;
    }
}

t_map** 	init_map(int height, int width)
{
  t_map 	**map;

  srand((unsigned int)time(NULL));
  map = create_map(height, width);
  fill_map(map, height, width);
  generate_stone(map, height, width);
  return (map);
}
