/*
** egg.c for zappy in /home/alexandre/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Sat Jun 27 18:58:06 2015 Alexandre PAGE
** Last update Fri Jul  3 15:07:49 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>

t_players	*get_egg(t_players *players, char *team)
{
  t_players	*player;

  player = players->next;
  while (player != players)
    {
      if (player->team_name && !strcmp(player->team_name, team)
	  && player->isegg == TRUE && player->ghost == TRUE)
	return (player);
      player = player->next;
    }
  return (NULL);
}
