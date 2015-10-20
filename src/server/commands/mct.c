/*
** bct2.c for zappy in /home/alex/rendu/zappy/src/server/commands
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Sun Jun 21 11:45:00 2015 Alexandre PAGE
** Last update Fri Jul  3 14:50:44 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>

void	mct(t_env *client, int fd, char **arg)
{
  char	*str;
  int	x;
  int	y;

  (void)arg;
  y = 0;
  while (y < client->parser->height)
    {
      x = 0;
      while (x < client->parser->width)
	{
	  asprintf(&str, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
		   client->map[x][y].food, client->map[x][y].linemate,
		   client->map[x][y].deraumere, client->map[x][y].sibur,
		   client->map[x][y].mendiane, client->map[x][y].phiras,
		   client->map[x][y].thystame);
	  write_on_client(str, fd);
	  x = x + 1;
	}
      y = y + 1;
    }
}
