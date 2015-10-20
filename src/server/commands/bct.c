/*
** bct.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Fri Jun 19 18:33:28 2015 Alexandre PAGE
** Last update Fri Jul  3 14:46:39 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/commands.h>
#include <server/lib.h>

void	bct(t_env *client, int fd, char **arg)
{
  int	x;
  int	y;
  char	*str;

  if (arg[0] && arg[1] && arg[2])
    {
      if ((x = atoi(arg[1])) < 0 || (y = atoi(arg[2])) < 0)
	sbp(client, fd, arg);
      else
	{
	  asprintf(&str, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
		   client->map[x][y].food, client->map[x][y].linemate,
		   client->map[x][y].deraumere, client->map[x][y].sibur,
		   client->map[x][y].mendiane, client->map[x][y].phiras,
		   client->map[x][y].thystame);
	  write_on_client(str, fd);
	  xfree(str);
	}
    }
  else
    sbp(client, fd, arg);
}
