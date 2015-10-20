/*
** token_food.c for zappy in /home/alex/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Tue Jun 23 13:20:25 2015 Alexandre PAGE
** Last update Sun Jul  5 13:37:31 2015 Alexandre PAGE
*/

#include <server/server.h>
#include <server/socket.h>
#include <server/commands.h>

int			get_token_food(char *food)
{
  static const char	*stone[] = {"nourriture", "linemate",
				    "deraumere", "sibur", "mendiane",
				    "phiras", "thystame", NULL};
  int	i;

  i = 0;
  while (stone[i])
    {
      if (!strcmp(food, stone[i]))
	return (i);
      i = i + 1;
    }
  return (-1);
}
