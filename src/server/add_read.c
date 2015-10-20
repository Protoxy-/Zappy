/*
** socket.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Mon Jun 15 17:39:38 2015 Alexandre PAGE
** Last update Sun Jul  5 19:53:12 2015 Alexandre ARRAMON
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/commands.h>
#include <server/lib.h>

void		read_client(int fd, t_env *e)
{
  t_players	*player;
  t_monitors	*monitor;

  printf("%s : Connection closed\n",
	 e->name[fd]);
  close(fd);
  player = get_player_from_id(e->players, fd);
  xfree(e->name[fd]);
  if (player && player->pnw == TRUE && e->fd_type[fd] != FD_GRAPHICAL_SERVER
      && player->team_name)
    {
      printf("Putting the player in ghost mode\n");
      change_available_slots(e->parser->teams, player->team_name,
			     get_available_slots(e->parser->teams,
						 player->team_name) + 1);
      player->ghost = TRUE;
      player->pnw = FALSE;
      player->id = -1;
    }
  else if ((monitor = get_monitor_from_id(e->monitors, fd)) != NULL)
    {
      printf("Delete monitor\n");
      delete_monitor(monitor);
    }
  e->fd_type[fd] = FD_FREE;
}

void	client_read(t_env *e, int fd, void (*tabptrfn[])())
{
  int	r;
  char	buf[BUFFER];

  bzero(buf, BUFFER);
  if ((r = (int)read(fd, buf, BUFFER - 1)) > 0)
    buf[r - 1] = '\0';
  else
    read_client(fd, e);
  printf("Received from client %d : %s\n", fd, buf);
  client_choose_func(e, fd, buf, tabptrfn);
}

int			add_client(t_env *e, int s)
{
  int			cs;
  struct sockaddr_in	client_sin;
  socklen_t		client_sin_len;
  char			str[12];

  client_sin_len = sizeof(client_sin);
  if ((cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len)) == -1)
    xexit(s, strerror(errno));
  e->fd_type[cs] = FD_CLIENT;
  e->fct_read[cs] = client_read;
  e->fct_write[cs] = sendmess;
  sprintf(str, "Player %d", cs);
  e->name[cs] = strdup(str);
  dprintf(cs, "BIENVENUE\n");
  return (cs);
}

void	server_read(t_env *e, int fd)
{
  int	cs;

  cs = add_client(e, fd);
  printf("New client : %d\n", cs);
}

void			add_server(t_env *e, t_map **map, int port)
{
  int			s;
  struct sockaddr_in	sin;

  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    xexit(s, strerror(errno));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    xexit(s, strerror(errno));
  if (listen(s, 42) == -1)
    xexit(s, strerror(errno));
  e->fd_type[s] = FD_SERVER;
  e->fct_read[s] = server_read;
  e->fct_write[s] = NULL;
  e->map = map;
}
