/*
** ghost.c for zappy in /home/alexandre/rendu/zappy/src/server
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Fri Jun 26 22:38:53 2015 Alexandre PAGE
** Last update Fri Jul  3 15:09:30 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/lib.h>
#include <server/commands.h>

t_players	*get_ghost(t_players *players, char *team_name)
{
  t_players	*player;

  player = players->next;
  while (player != players)
    {
      if (player->ghost == TRUE && !strcmp(team_name, player->team_name))
	return (player);
      player = player->next;
    }
  return (NULL);
}

void	remplacing_player(t_players *playerghost, int fd, t_env *e)
{
  (void) fd;
  printf("Detection ghost id = %d fd = %d\n", playerghost->id, fd);
  playerghost->pnw = TRUE;
  playerghost->ghost = FALSE;
  playerghost->id = fd;
  if (playerghost->isegg == TRUE)
    ebo(e, playerghost);
  pnw(e, playerghost);
  communicate_coordonate(e->parser, fd);
}
