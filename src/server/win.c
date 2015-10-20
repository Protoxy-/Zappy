/*
** win.c for zappy in /home/alexandre/rendu/zappy
** 
** Made by Alexandre PAGE
** Login   <page_a@epitech.eu>
** 
** Started on  Thu Jun 25 18:50:37 2015 Alexandre PAGE
** Last update Fri Jul  3 15:59:45 2015 Maxime JUNGER
*/

#include <server/socket.h>
#include <server/server.h>
#include <server/lib.h>

static int	count_nbr_team(t_teams *teams)
{
  int		i;
  t_teams	*tmp;

  i = 0;
  tmp = teams->next;
  while (tmp != teams)
    {
      i = i + 1;
      tmp = tmp->next;
    }
  return (i);
}

static int	*tab_team(int nbr_team, t_teams *teams)
{
  int		i;
  int		*team;

  i = 0;
  nbr_team = count_nbr_team(teams);
  team = xmalloc(sizeof(*team) * nbr_team);
  i = 0;
  while (i < nbr_team)
    {
      team[i] = 0;
      i++;
    }
  return (team);
}

static void	fill_the_tab_score(int *team, t_env *e)
{
  t_teams	*tmp;
  t_players	*player;
  int		i;
  int		count;

  i = 0;
  tmp = e->parser->teams->next;
  while (tmp != e->parser->teams)
    {
      count = 0;
      player = e->players->next;
      while (player != e->players)
	{
	  if (player->pnw == TRUE && !strcmp(player->team_name, tmp->name))
	    {
	      if (player->level == 8)
		count++;
	    }
	  player = player->next;
	}
      team[i] = count;
      i = i + 1;
      tmp = tmp->next;
    }
}

static char	*get_team_from_id(t_teams *teams, int id)
{
  t_teams	*team;
  int		i;

  i = 0;
  team = teams->next;
  while (team != teams)
    {
      if (id == i)
	return (team->name);
      i = i + 1;
      team = team->next;
    }
  return (NULL);
}

void	check_win(t_env *e)
{
  int	nbr_team;
  int	*team;
  int	i;
  char	*str;
  char	*copy_team;

  nbr_team = count_nbr_team(e->parser->teams);
  team = tab_team(nbr_team, e->parser->teams);
  fill_the_tab_score(team, e);
  i = 0;
  while (i < nbr_team)
    {
      if (team[i] >= 6)
	{
	  copy_team = strdup(get_team_from_id(e->parser->teams, i));
	  asprintf(&str, "seg %s\n", copy_team);
	  xfree(copy_team);
	  send_mess_graphic_client(e, str);
	  exiting(e);
	}
      i++;
    }
  xfree(team);
}
