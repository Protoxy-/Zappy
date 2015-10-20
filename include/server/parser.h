/*
** parser.h for parser in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/parser
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Fri Jun 12 17:33:06 2015 Maxime JUNGER
** Last update Fri Jul  3 16:42:31 2015 Maxime JUNGER
*/

#ifndef PARSER_H_
# define PARSER_H_

# define FUNC_NBR 6

# include <stdlib.h>
# include <server/server.h>

typedef int bool;

typedef struct		s_teams
{
  char			*name;
  unsigned int		available_slots;
  struct s_teams	*prev;
  struct s_teams	*next;
}			t_teams;

typedef struct		s_parser
{
  double		port;
  int			width;
  int			height;
  int			authorized_clients;
  t_teams		*teams;
  double			delay;
}			t_parser;

void	parse(t_parser *entry, char **av);

/*
** PARSER_TABPTR.C
*/

void	init_tabptr(void (*tabptrfunc[])());

/*
** TABPTR_FUNC
*/

void	authorized_clients(t_parser *, char *);
void	delay(t_parser *, char *);
char	*transform_to_good_teams(char **tab);
char	**get_function_tab();

/*
** LIST
*/

void	my_show_list(t_teams *list);
int	my_strlen_list(t_teams *list);
t_teams	*my_creat_teams(t_teams *elem);
int	my_put_in_list(t_teams *list, char *str);
void	y_delete_list(t_teams *list);

int	get_available_slots(t_teams *list, char *name);
void	change_available_slots(t_teams *list, char *team, int nb);
void	set_all_available_slots(t_teams *list, int nb);
int	get_number_teams(t_teams *list);
bool	check_if_team_exist(t_teams *list, char *name);


#endif /* !PARSER_H_ */
