/*
** error_manager.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Fri Jul  3 13:24:40 2015 Maxime JUNGER
** Last update Sun Jul  5 16:20:26 2015 Alexandre ARRAMON
*/

#include <server/socket.h>
#include <server/lib.h>
#include <server/parser.h>
#include <server/server.h>
#include <server/list_wait_functions.h>
#include <server/commands.h>

void	xexit(int fd, char *str)
{
  close(fd);
  fprintf(stderr, "%s\n", str);
  exit(EXIT_FAILURE);
}

void	xerror(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(EXIT_FAILURE);
}

void	usage_error()
{
  fprintf(stderr, "usage: "
	  "./server [[[-p port] -p port] ...] "
	  "[-x world_x] [-y world_y] [-c max_"
	  "clients] [-t speed] -n team_name_1"
	  " team_name_2 ...\n");
  exit(EXIT_FAILURE);
}
