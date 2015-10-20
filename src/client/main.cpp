//
// main.cpp for main in /home/froehl_f/rendu/zappy/src/client
// 
// Made by Fabrice Froehly
// Login   <froehl_f@epitech.net>
// 
// Started on  Tue Jun 16 15:57:31 2015 Fabrice Froehly
// Last update Tue Jun 23 14:25:45 2015 Alexandre ARRAMON
//

#include "Client.hh"

int	main(int ac, const char **av)
{
  Client	*client;

  client = new Client();
  if (!client->init(ac, av))
    return (1);
  client->selectLoop();
}
