/*
** sound_manager.c for sound in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/sound
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Mon Jun 29 10:38:48 2015 Maxime JUNGER
** Last update Sun Jul  5 13:53:21 2015 Alexandre PAGE
*/

#include <server/server.h>
#include <server/socket.h>
#include <server/sound.h>

t_sound		get_sound_direction(t_env *e, t_players *sender,
				    t_players *listener)
{
  t_sound	dist;
  int		x;
  int		y;

  dist.x = INIT_X;
  dist.y = INIT_Y;
  if (sender == NULL || listener == NULL)
    return (dist);
  x = sender->playerx - listener->playerx;
  y = sender->playery - listener->playery;
  if (x == 0)
    dist.x = NONE_X;
  else if (abs(x) > (e->parser->width / 2))
    dist.x = (x > 0) ? LEFT : RIGHT;
  else
    dist.x = (x > 0) ? RIGHT : LEFT;
  if (y == 0)
    dist.y = NONE_Y;
  else if (abs(y) > (e->parser->height / 2))
    dist.y = (y > 0) ? UP : DOWN;
  else
    dist.y = (y > 0) ? DOWN : UP;
  return (dist);
}

int	get_case_of_sound(t_players *listener, t_sound *sd)
{
  int	res;
  int	(*fct[5])(t_sound *);

  fct[0] = &oriented_up;
  fct[1] = &oriented_right;
  fct[2] = &oriented_down;
  fct[3] = &oriented_left;
  fct[4] = NULL;
  res = fct[listener->orientation - 1](sd);
  return (res);
}

int	get_sound_coming_case(t_env *e, t_players *sender, t_players *listener)
{
  int	result;
  t_sound	sd;

  sd = get_sound_direction(e, sender, listener);
  if (sd.x == INIT_X && sd.y == INIT_Y)
    return (-1);
  result = get_case_of_sound(listener, &sd);
  return (result);
}
