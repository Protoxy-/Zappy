/*
** lib.h for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/lib
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Mon Jun 15 15:32:40 2015 Maxime JUNGER
** Last update Fri Jul  3 17:32:32 2015 Maxime JUNGER
*/

#ifndef LIB_H_
# define LIB_H_

#include <server/parser.h>
#include <server/incantation.h>

typedef struct s_players	t_players;

void		my_check_string(char *);
char		**my_str_to_wordtab(char *, char);
void 		free_str_to_wordtab(void **);
t_players	*init_player(t_players *);
void		add_player_to_list(t_players *list, t_players *new);
void		delete_player(t_players *, t_env *);
int		create_player(t_players *, t_parser *, int);
void		delete_list(t_players *);
void		free_tab(void **);
void		xfree(void *);
void		*xmalloc(size_t);
void		*xrealloc(void *, size_t);

t_incantation	*incantation_start(t_env *, int, char **);

t_monitors	*init_monitors(t_monitors *);
int		create_monitors(t_monitors *, int);
t_monitors	*get_monitor_from_id(t_monitors *, int);

int		get_number_players(t_players *list);

long long	get_current_time();
long long	convert_seconde_mili(double);
int		get_wait_time(int);
int 		str_list_queue(t_wait *);

t_players	*get_egg(t_players *, char *);

void		xerror(char *str);
void		xexit(int, char *);

void	communicate_coordonate(t_parser *, int);

#endif /* !LIB_H_ */
