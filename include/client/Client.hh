//
// Client.hh for Client in /home/froehl_f/rendu/zappy/include/client
// 
// Made by Fabrice Froehly
// Login   <froehl_f@epitech.net>
// 
// Started on  Tue Jun 16 16:47:37 2015 Fabrice Froehly
// Last update Wed Jul  1 14:37:13 2015 Fabrice Froehly
//

#ifndef CLIENT_HH_
# define CLIENT_HH_

#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string>
#include <iostream>
#include "IA.hh"

class	Client
{
public:
  Client();
  ~Client();
  bool		init(int ac, const char **av);
  bool		checkParameters(int ac, const char **av, int &);
  void		setFD(fd_set *fd_read, fd_set *fd_write);
  void		findFDRead(fd_set *fd_read);
  void		findFDWrite(fd_set *fd_write);
  void		selectLoop();
  bool		checkEndMessage();
  void		getLine();
  void		getBuffInTab(const std::string &);

private:
  IA				_ia;
  int				_fd;
  std::string			_buffOut;
  std::string			_buffIn;
  bool				_rcvMsg;
  std::list<std::string>	_tabBuff;
};

#endif /* !CLIENT_HH_ */
