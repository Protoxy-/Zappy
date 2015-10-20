/*
** time_manager.c for time in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/lib
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Wed Jun 24 10:53:38 2015 Maxime JUNGER
** Last update Sun Jul  5 13:49:48 2015 Alexandre PAGE
*/

#include <sys/time.h>
#include <server/lib.h>
#include <server/server.h>
#include <server/parser.h>

long long		get_current_time()
{
  struct timeval	te;
  long long		milliseconds;

  gettimeofday(&te, NULL);
  milliseconds = (1000 * te.tv_sec) + (te.tv_usec / 1000);
  return (milliseconds);
}

long long	convert_seconde_mili(double sec)
{
  long long	milliseconds;

  milliseconds = sec * 1000;
  return (milliseconds);
}

int	get_wait_time(int token)
{
  int	value;

  if (token == 4)
    value = 1;
  else if (token == 9)
    value = 300;
  else if (token == 10)
    value = 42;
  else if (token == 8)
		value = 1;
	else
    value = 7;
  return (value);
}
