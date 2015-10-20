/*
** health_player.c for zappy in /home/alexandre/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Thu Jun 25 11:54:57 2015 Alexandre PAGE
** Last update Sun Jul  5 19:55:06 2015 Alexandre ARRAMON
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/lib.h>

void		decrease_health(t_players *players, t_parser *parser)
{
  t_players	*player;

  player = players->next;
  while (player != players)
    {
      if (player->pnw == TRUE && player->ghost == FALSE
	  && (get_current_time() > (player->timestamp_health
	 + (convert_seconde_mili((double)(126) / parser->delay)))))
	{
	  player->timestamp_health = get_current_time();
	  player->inventory->food -= 1;
	  printf("%d food : %d\n", player->id, player->inventory->food);
	}
      player = player->next;
    }
}

void		check_death_player(t_players *players, t_env *e)
{
  t_players	*player;
  t_players *tmp;
  char		*str;

  player = players->next;
  while (player != players)
    {
      if (player->inventory->food <= 0)
	{
	  if (player->isegg == TRUE)
	    asprintf(&str, "edi %d\n", player->id);
	  else
	    asprintf(&str, "pdi %d\n", player->id);
	  send_mess_graphic_client(e, str);
	  write_on_client("mort\n", player->id);
  	tmp = player;
	  if (close(tmp->id) == -1)
	    printf("Error on close()\n");
	player = player->next;
	delete_player(tmp, e);
	}
	else
      player = player->next;
    }
}
