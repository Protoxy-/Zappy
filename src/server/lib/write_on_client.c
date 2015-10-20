/*
** write_on_client.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Thu Jun 18 17:39:33 2015 Maxime JUNGER
** Last update Sun Jul  5 13:50:11 2015 Alexandre PAGE
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <server/server.h>

void			write_on_client(char *str, int fd)
{
  unsigned long	i;
  unsigned long	j;

  j = 0;
  i = 0;
  while ((i = write(fd, str + i, strlen(str))) < strlen(str))
    {
      if (j >= 10)
	return ;
      j++;
    }
}
