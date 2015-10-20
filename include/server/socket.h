/*
** socket.h for lol in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Mon Jun 15 17:33:28 2015 Alexandre PAGE
** Last update Fri Jul  3 17:33:32 2015 Maxime JUNGER
*/

#ifndef SOCKET_H_
# define SOCKET_H_

# define _GNU_SOURCE

/*
** INCLUDE
*/

# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <netdb.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <server/parser.h>

/*
** MACCRO
*/

# define FD_FREE 0
# define FD_CLIENT 1
# define FD_SERVER 2
# define FD_GRAPHICAL_SERVER 3
# define MAX_FD 255
# define BUFFER 4096
# define FALSE 0
# define TRUE !FALSE

typedef void			(*fct)();
typedef struct s_map		t_map;
typedef int bool;
typedef struct s_parser		t_parser;
typedef struct s_wait		t_wait;
typedef struct s_monitors	t_monitors;

typedef struct  	s_env
{
  int          		fd_type[MAX_FD];
  fct		        fct_read[MAX_FD];
  fct		        fct_write[MAX_FD];
  char*			buf[MAX_FD];
  char*			name[MAX_FD];
  struct s_players*	players;
  struct s_monitors*    monitors;
  t_map**		map;
  long 			time;
  t_wait 		*actionQueue;
  t_parser*		parser;
}               	t_env;

void	client_read(t_env *, int, void (*tabptrfn[])());
int 	add_client(t_env *, int);
void	server_read(t_env *, int);
void	add_server(t_env *, t_map **, int);

void	init_serv(t_env *, t_map **, int);
int	browse_set_client(t_env *, fd_set *, fd_set *);
void	look_over_client(t_env *, int, char[]);
void	sendmess(t_env *, int);

int	get_token(char *);
void	initab(void (*tabptrfunc[])());
int	get_token_serv(char *);
void	init_tab_monitor(void (*tabptrfunc[])());

#endif /* !SOCKET_H_ */
