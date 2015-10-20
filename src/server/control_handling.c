/*
** control_handling.c for azer in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV/src/server
** 
** Made by Maxime JUNGER
** Login   <junger_m@epitech.eu>
** 
** Started on  Sun Jul  5 20:44:04 2015 Maxime JUNGER
** Last update Sun Jul  5 20:44:05 2015 Maxime JUNGER
*/

#include <server/server.h>
#include <server/commands.h>

void	signal_handler()
{
	t_players	*tmp;

	tmp = g_data->next;
	while (tmp != g_data)
	{
		write_on_client("mort\n", tmp->id);
		tmp = tmp->next;
	}
	exit(0);
}