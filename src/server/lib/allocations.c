/*
** allocations.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/lib
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Sun Jun 21 18:35:49 2015 Maxime JUNGER
** Last update Fri Jul  3 15:17:20 2015 Maxime JUNGER
*/

#include <stdlib.h>
#include <unistd.h>
#include <server/server.h>

void	free_tab(void **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  if (tab)
    free(tab);
}

void	xfree(void *ptr)
{
  if (ptr)
    free(ptr);
}

void	*xmalloc(size_t t)
{
  void	*p;

  p = malloc(t);
  if (p == NULL)
    xerror("Malloc failed");
  return (p);
}

void	*xrealloc(void *p, size_t t)
{
  p = realloc(p, t);
  if (p == NULL)
    xerror("Realloc failed");
  return (p);
}
