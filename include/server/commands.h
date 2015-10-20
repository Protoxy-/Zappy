/*
** commands.h for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Thu Jun 18 15:59:30 2015 Maxime JUNGER
** Last update Sun Jul  5 13:18:54 2015 Alexandre PAGE
*/

#ifndef COMMANDS_H_
# define COMMANDS_H_

# include <server/server.h>

# define UNKNOWN_COMMAND "suc\n"
# define UNKNOWN_TEAM "smg Unknown team\n"
# define WRONG_PARAM "sbp\n"
# define OK "ok\n"
# define KO "ko\n"

void	msz(t_env *, int, char **);
void	bct(t_env *, int, char **);
void	mct(t_env *, int, char **);
void	tna(t_env *, int, char **);
void	ppo(t_env *, int, char **);
void	plv(t_env *, int, char **);
void	pin(t_env *, int, char **);
void	pex(t_env *, int, char **);
void	pbc(t_env *, int, char **);
void	pic(t_env *, int, char **);
void	pie(t_env *, int, char **);
void	pfk(t_env *, int, char **);
void	pdr(t_env *, int, char **);
void	pgt(t_env *, int, char **);
void	pdi(t_env *, int, char **);
void	enw(t_env *, int, char **);
void	eht(t_env *, int, char **);
void	edi(t_env *, int, char **);
void	sgt(t_env *, int, char **);
void	sgt_set(t_env *, int, char **);
void	seg(t_env *, int, char **);
void	suc(t_env *, int, char **);
void	sbp(t_env *, int, char **);

void	ppop(t_players *, t_env *);
void	ebo(t_env *, t_players *);

void	pfkserver(t_env *, int);

void	teamname(t_env *, int, char **);
void	graphic(t_env *, int, char **);
void	pnw(t_env *, t_players *player);
void	need_pnw(t_env *);
void	smg(int, char *);

void	move_on(t_env *, int, char **);
void	turn_left(t_env *, int, char **);
void	turn_right(t_env *, int, char **);
void	see(t_env *, int, char **);
void	inventory(t_env *, int, char **);

void	connect_nbr(t_env *, int, char **);

void	take_throw_out_graphical_send(t_players *, t_map *, t_env *);
void	map_init_tabptr2(bool (*maptabptrfunc[])());

int	**choose_position(t_players *, int);

void	north(int, int, t_env *, t_players *);
void	east(int, int, t_env *, t_players *);
void	south(int, int, t_env *, t_players *);
void	init_ressource(int (*map_tabptrfn[NBR_STONE + 1])());

void	print_stone(int, t_env *, int, int);

#endif /* !COMMANDS_H_ */
