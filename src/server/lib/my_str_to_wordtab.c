/*
** my_str_to_wordtab.c for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server/lib
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Sat Jun 27 14:47:22 2015 Maxime JUNGER
** Last update Fri Jul  3 15:47:43 2015 Maxime JUNGER
*/

#include <stdlib.h>
#include <string.h>
#include <server/lib.h>

int	my_nbr_word(char *str, char sep)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (str[i] != sep && str[i] != '\t')
	count = count + 1;
      while (str[i + 1] && (str[i] != sep && str[i] != '\t'))
	i++;
      i++;
    }
  return (count);
}

int	my_nbr_char(char *str, int *i, char sep)
{
  int	count;

  count = 0;
  while (str[*i] && (str[*i] != sep && str[*i] != '\t'))
    {
      count = count + 1;
      *i = *i + 1;
    }
  return (count);
}

char	**my_str_to_wordtab(char *str, char sep)
{
  char	**tab;
  int	i;
  int	j;
  int	nb_word;

  i = 0;
  j = 0;
  nb_word = my_nbr_word(strdup(str), sep);
	tab = xmalloc((nb_word + 1) * sizeof(char *));
  while (str && str[i] && nb_word > 0)
    {
      if (str[i] != sep && str[i] != '\t')
	{
	  tab[j] = strdup(str + i);
	  tab[j][my_nbr_char(str, &i, sep)] = '\0';
	  j = j + 1;
	  nb_word = nb_word - 1;
	}
      i++;
    }
  tab[my_nbr_word(strdup(str), sep)] = NULL;
  return (tab);
}

void	free_str_to_wordtab(void **str)
{
  int   i;

  i = 0;
  while (str[i])
  {
    xfree(str[i]);
    i = i + 1;
  }
  xfree(str);
}
