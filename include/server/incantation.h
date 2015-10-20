/*
** incantation.h for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Sat Jun 27 14:51:38 2015 Maxime JUNGER
** Last update Fri Jul  3 16:38:38 2015 Maxime JUNGER
*/

#ifndef INCANTATION_H_
# define INCANTATION_H_

# include <server/server.h>

typedef struct	s_incantation
{
  t_players	*players;
  t_players	*who_asked;
  int		start_x;
  int		start_y;
}		t_incantation;

t_incantation	*incantation_start(t_env *e, int fd, char **arg);
void		incantation_stop(t_env *e, int fd, char **arg, t_incantation *);

t_players	*get_players_on_case(t_env *e, int pos_x, int pos_y);
void		set_incantate_struct(t_wait *w, t_incantation *inc);
void		send_mess_to_graphic(t_env *, t_incantation *);
void		write_to_all_players(char *str, t_players *);
void		init_res(t_incantation *res);

#endif /* !INCANTATION_H_ */
