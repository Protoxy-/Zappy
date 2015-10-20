/*
** my_check_pointer.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/lib
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Mon Jun 15 15:31:04 2015 Maxime JUNGER
** Last update Mon Jun 15 15:35:45 2015 Maxime JUNGER
*/

#include <stdlib.h>
#include <stdio.h>
#include <server/lib.h>

void	my_check_string(char *ptr)
{
  if (ptr == NULL)
    {
      printf("String is NULL.\n");
      exit(-1);
    }
}
