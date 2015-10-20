/*
** oriented_right.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/sound
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Mon Jun 29 13:48:46 2015 Maxime JUNGER
** Last update Fri Jul  3 15:52:02 2015 Maxime JUNGER
*/

#include <server/server.h>
#include <server/socket.h>
#include <server/sound.h>

int	oriented_right(t_sound *sd)
{
  int	res;

  res = 0;
  if (sd->x == RIGHT && sd->y == NONE_Y)
    res = 1;
  else if (sd->x == RIGHT && sd->y == UP)
    res = 2;
  else if (sd->x == NONE_X && sd->y == UP)
    res = 3;
  else if (sd->x == LEFT && sd->y == UP)
    res = 4;
  else if (sd->x == LEFT && sd->y == NONE_Y)
    res = 5;
  else if (sd->x == LEFT && sd->y == DOWN)
    res = 6;
  else if (sd->x == NONE_X && sd->y == DOWN)
    res = 7;
  else if (sd->x == RIGHT && sd->y == DOWN)
    res = 8;
  return (res);
}