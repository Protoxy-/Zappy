/*
** eht.c for zappy in /home/alexandre/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Fri Jun 26 10:36:49 2015 Alexandre PAGE
** Last update Fri Jul  3 14:47:55 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>
#include <server/lib.h>

void		eht(t_env *e, int fd, char **arg)
{
  t_players	*player;
  t_players	*playeregg;
  int		n;
  char		*str;

  (void) arg;
  player = get_player_from_id(e->players, fd);
  n = get_available_slots(e->parser->teams, player->team_name);
  change_available_slots(e->parser->teams, player->team_name, n + 1);
  create_player(e->players, e->parser, player->idegg);
  if ((playeregg = get_player_from_id(e->players, player->idegg)) != NULL)
    {
      printf("New client (ghost | fork): %d\n", player->idegg);
      playeregg->playerx = player->playerxegg;
      playeregg->playery = player->playeryegg;
      playeregg->isegg = TRUE;
      playeregg->ghost = TRUE;
      playeregg->team_name = strdup(player->team_name);
      playeregg->idegg = player->idegg;
      player->idegg = -1;
      asprintf(&str, "eht %d\n", playeregg->id);
      send_mess_graphic_client(e, str);
    }
}
