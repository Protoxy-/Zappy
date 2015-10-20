/*
** server.h for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/include
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Fri May  1 14:20:20 2015 Maxime JUNGER
** Last update Sun Jul  5 13:14:02 2015 Alexandre PAGE
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <server/socket.h>
# include <time.h>

# define NBR_FUNC 12
# define NBR_STONE 7
# define NBR_SERV 10

typedef int		bool;
typedef struct s_env	t_env;
typedef struct s_map	t_inventory;
typedef struct s_parser	t_parser;

enum direction
  {
    N = 1,
    E = 2,
    S = 3,
    O = 4,
  };

typedef struct	s_map
{
  int 		food;
  int 		linemate;
  int 		deraumere;
  int 		sibur;
  int 		mendiane;
  int 		phiras;
  int 		thystame;
} 		t_map;

typedef struct 			s_players
{
  int 				id;
  int				playerx;
  int 				playery;
  int 				level;
  char				*team_name;
  enum direction 		orientation;
  bool 				pnw;
  long long 			timestamp_health;
  bool				is_elevating;
  int 				playerxegg;
  int 				playeryegg;
  int 				idegg;
  bool 				isegg;
  bool 				ghost;
  t_inventory			*inventory;
  struct s_players		*next;
  struct s_players		*prev;
}				t_players;

typedef struct		s_monitors
{
  int 			id;
  struct s_monitors	*next;
  struct s_monitors	*prev;
}			t_monitors;

typedef struct		s_teamname
{
  char 			*name;
  struct s_teamname	*next;
}			t_teamname;

typedef struct 	s_server
{
  int		port;
  int		height;
  int		width;
  int		playerPerTeam;
  int		timeDelay;
}		t_server;

void	signal_handler();

void		msz(t_env *, int, char **);
void      	xexit(int, char *);
void      	xerror(char *);
void      	usage_error();
void    	write_on_client(char *str, int fd);

/*
** server/map/map_init.c
*/

t_map**		init_map(int, int);

/*
** server/map/map_tabptr.c
*/

void 		map_init_tabptr(bool (*maptabptrfunc[])());
bool 		inc_linemate(t_map *);
bool 		inc_deraumere(t_map *);
bool 		inc_food(t_map *);

/*
** server/map/map_func_stone.c
*/

bool 		inc_sibur(t_map *);
bool 		inc_mendiane(t_map *);
bool 		inc_phiras(t_map *);
bool 		inc_thystame(t_map *);

/*
** server/map/dec_ressource.c
*/

bool		dec_linemate(t_map *);
bool		dec_deraumere(t_map *);
bool		dec_food(t_map *);
bool		dec_sibur(t_map *);
bool		dec_mendiane(t_map *);

/*
**server/map/dec_ressource_func.c
*/

bool		dec_phiras(t_map *);
bool		dec_thystame(t_map *);

/*
** server/player.c
*/

void 		generate_position(t_players *, t_parser *);
t_inventory	*init_inventory(void);
t_players 	*get_player_from_id(t_players *, int);
void 		generate_orientation(t_players *);

/*
** server/add_read_func.c
*/

void		client_read_next(t_env *, int, char[], char **);
void		client_choose_func(t_env *, int, char[], void (*tabptrfn[])());

/*
** server/graphic.c
*/
void		send_mess_graphic_client(t_env *, char *);

/*
** server/token_food.c
*/

int		get_token_food(char *);

/*
** server/get_ressources.c
*/

int		get_food(t_map *);
int		get_linemate(t_map *);
int		get_deraumere(t_map *);
int		get_sibur(t_map *);
int		get_mendiane(t_map *);
int		get_player(t_players *, int, int);

/*
** server/get_ressources_func.c
*/

int		get_phiras(t_map *);
int		get_thystame(t_map *);

/*
** server/health_player.c
*/

void		decrease_health(t_players *, t_parser *);
void		check_death_player(t_players *, t_env *);

/*
** server/exit.c
*/

void		exiting(t_env *);

/*
** server/win.c
*/

void		check_win(t_env *);

/*
** elevation
*/

bool		level_1(t_map *map, t_players *list);
bool		level_2(t_map *map, t_players *list);
bool		level_3(t_map *map, t_players *list);
bool		level_4(t_map *map, t_players *list);
bool		level_5(t_map *map, t_players *list);
bool		level_6(t_map *map, t_players *list);
bool		level_7(t_map *map, t_players *list);

/*
** server/ghost.c
*/

t_players	*get_ghost(t_players *, char *);
void		remplacing_player(t_players *, int, t_env *);
void	       	delete_monitor(t_monitors *list);

t_players	*g_data;

#endif /* !SERVER_H_ */
