/*
** exit.c for zappy in /home/alexandre/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Thu Jun 25 20:31:43 2015 Alexandre PAGE
** Last update Fri Jul  3 15:08:40 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/lib.h>

void	exiting(t_env *e)
{
  int	i;

  i = 0;
  while (i < MAX_FD)
    {
      if (e->fd_type[i] != FD_FREE)
	{
	  if (close(i) == -1)
	    xerror("Error on close()\n");
	}
      i++;
    }
  exit(EXIT_SUCCESS);
}
