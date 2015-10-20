/*
** server.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Thu Jun 18 18:02:04 2015 Alexandre PAGE
** Last update Fri Jul  3 15:51:24 2015 Maxime JUNGER
*/

#include <server/server.h>
#include <server/socket.h>
#include <server/lib.h>

void	init_serv(t_env *e, t_map **map, int port)
{
  int	i;

  i = 0;
  while (i < MAX_FD)
    {
      e->name[i] = NULL;
      e->fd_type[i] = FD_FREE;
      i = i + 1;
    }
  memset(e->fd_type, FD_FREE, MAX_FD);
  memset(e->buf, 0, sizeof(e->buf));
  e->players = init_player(e->players);
  add_server(e, map, port);
}

int	browse_set_client(t_env *e, fd_set *fd_read, fd_set *fd_write)
{
  int	fd_max;
  int	i;

  i = 0;
  fd_max = 0;
  while (i < MAX_FD)
    {
      if (e->buf[i] != NULL)
	FD_SET(i, fd_write);
      if (e->fd_type[i] != FD_FREE)
	{
	  FD_SET(i, fd_read);
	  fd_max = i;
	}
      i += 1;
    }
  decrease_health(e->players, e->parser);
  check_death_player(e->players, e);
  check_win(e);
  return (fd_max);
}

void	look_over_client(t_env *e, int fd, char buf[])
{
  char	my_str[BUFFER];

  sprintf(my_str, "%s : %s\n", e->name[fd], buf);
  if (e->fd_type[fd] == FD_CLIENT)
    {
      if (e->buf[fd] == NULL)
	e->buf[fd] = strdup(my_str);
      else
	e->buf[fd] = xrealloc(e->buf[fd],
			      sizeof(char) * (strlen(my_str)
					      + strlen(e->buf[fd]) + 1));
    }
}

void	sendmess(t_env *e, int fd)
{
  write(fd, e->buf[fd], strlen(e->buf[fd]));
}
