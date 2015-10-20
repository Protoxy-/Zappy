/*
** pnw.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Sun Jun 21 13:58:38 2015 Alexandre PAGE
** Last update Fri Jul  3 15:00:38 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/lib.h>

void	pnw(t_env *client, t_players *player)
{
  char	*str;
  int	i;

  i = 0;
  asprintf(&str, "pnw %d %d %d %d %d %s\n", player->id, player->playerx,
	   player->playery, player->orientation,
	   player->level, player->team_name);
  while (i < MAX_FD)
    {
      if (client->fd_type[i] == FD_GRAPHICAL_SERVER)
	write_on_client(str, i);
      i = i + 1;
    }
  xfree(str);
}
