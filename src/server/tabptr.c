/*
** tabptr.c for zappy in /home/alex/rendu/zappy/src/server
** 
** Made by page_a
** Login   <alex@epitech.net>
** 
** Started on  Fri May  1 14:17:24 2015 page_a
** Last update Fri Jul  3 18:41:06 2015 Maxime JUNGER
*/

#include <server/server.h>
#include <server/socket.h>
#include <server/commands.h>
#include <server/lib.h>
#include <server/incantation.h>

void	initab(void (*tabptrfunc[])())
{
  tabptrfunc[0] = &move_on;
  tabptrfunc[1] = &turn_right;
  tabptrfunc[2] = &turn_left;
  tabptrfunc[3] = &see;
  tabptrfunc[4] = &inventory;
  tabptrfunc[5] = &pgt;
  tabptrfunc[6] = &pdr;
  tabptrfunc[7] = &pex;
  tabptrfunc[8] = &pbc;
  tabptrfunc[10] = &pfk;
  tabptrfunc[11] = &connect_nbr;
  tabptrfunc[NBR_FUNC] = NULL;
}

int	get_token(char *command)
{
  int	i;
  char	**str;

  str = my_str_to_wordtab("avance droite gauche voir inventaire prend pose "
			  "expulse broadcast "
			  "incantation fork connect_nbr", ' ');
  i = 0;
  while (str[i])
    {
      if (!strcmp(str[i], command))
	{
	  free_str_to_wordtab((void **)str);
	  return (i);
	}
      i = i + 1;
    }
  free_str_to_wordtab((void **)str);
  return (-1);
}

int	get_token_serv(char *command)
{
  int	i;
  char	**str;

  str = my_str_to_wordtab("msz GRAPHIC bct mct tna ppo plv pin sgt sst", ' ');
  i = 0;
  while (str[i])
    {
      if (!strcmp(str[i], command))
	{
	  free_str_to_wordtab((void **)str);
	  return (i);
	}
      i = i + 1;
    }
  free_str_to_wordtab((void **)str);
  return (-1);
}

void	init_tab_monitor(void (*tabptrfunc[])())
{
  tabptrfunc[0] = &msz;
  tabptrfunc[1] = &graphic;
  tabptrfunc[2] = &bct;
  tabptrfunc[3] = &mct;
  tabptrfunc[4] = &tna;
  tabptrfunc[5] = &ppo;
  tabptrfunc[6] = &plv;
  tabptrfunc[7] = &pin;
  tabptrfunc[8] = &sgt;
  tabptrfunc[9] = &sgt_set;
  tabptrfunc[NBR_SERV] = NULL;
}
