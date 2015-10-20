/*
** sound.h for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/sound
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Mon Jun 29 10:40:41 2015 Maxime JUNGER
** Last update Fri Jul  3 16:52:05 2015 Maxime JUNGER
*/

#ifndef SOUND_H_
# define SOUND_H_

enum sound_x
  {
    LEFT,
    RIGHT,
    NONE_X,
		INIT_X
  };

enum sound_y
  {
    UP,
    DOWN,
		NONE_Y,
		INIT_Y
  };

typedef struct	s_sound
{
  enum sound_x	x;
  enum sound_y	y;
}		t_sound;

int	get_sound_coming_case(t_env *e, t_players *sender, t_players *listener);
int	oriented_up(t_sound *);
int	oriented_down(t_sound *);
int	oriented_left(t_sound *);
int	oriented_right(t_sound *);

#endif /* !SOUND_H_ */
