/*
** list_wait_functions.h for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/lib
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Tue Jun 23 16:15:55 2015 Maxime JUNGER
** Last update Sat Jul  4 14:10:06 2015 Maxime JUNGER
*/

#ifndef LIST_WAIT_FUNC
# define LIST_WAIT_FUNC

# include <server/socket.h>
# include <server/incantation.h>

typedef struct		s_wait
{
  int			fd;
  char			**arg;
  void			(*fct)(t_env *, int, char **);
  long long		time_when_call;
  int			numerator;
  bool			is_incantation;
  t_incantation		*incant;
  struct s_wait 	*next;
  struct s_wait 	*prev;
}			t_wait;

t_wait			*my_creat_wait_list(t_wait *);
t_wait			*get_function_to_run(t_wait *list, t_env *);
void			put_in_wait_list(t_wait *, t_wait *);
int			nbr_waiting_functions(t_wait *);
void			delete_func(t_wait *);
t_wait			*new_wait_struct(int, char **, void (*fct)(), int);

#endif /* !LIST_WAIT_FUNC */
