//
// Client.cpp for Client in /home/froehl_f/rendu/zappy/src/client
// 
// Made by Fabrice Froehly
// Login   <froehl_f@epitech.net>
// 
// Started on  Tue Jun 16 16:51:11 2015 Fabrice Froehly
// Last update Sun Jul  5 21:25:15 2015 Alexandre ARRAMON
//

#include "Client.hh"

Client::Client() {}

Client::~Client() {}

bool	Client::checkParameters(int ac, const char **av, int &port)
{
  if ((ac < 5)
      || (ac >= 5 && (std::string(av[1]).compare("-n") != 0 || std::string(av[3]).compare("-p") != 0))
      || (ac >= 6 && (std::string(av[1]).compare("-n") != 0 || std::string(av[3]).compare("-p") != 0 || std::string(av[5]).compare("-h") != 0)))
    {
      std::cout << "Usage : ./client [-n] [TeamName] [-p] [Port] ([-h] [IP])" << std::endl;
      return false;
    }
  if (ac >= 5)
    port = std::atoi(av[4]);
  else
    {
      std::cout << "Couldn't set the port\n";
      return false;
    }
  _ia.setTeam(std::string(av[2]));
  return true;
}

bool      Client::init(int ac, const char **av)
{
  struct	sockaddr_in  s_in;
  struct	protoent *pe;
  int		port;
  std::string	ip;

  if (!checkParameters(ac, av, port))
    return false;
  ac < 7 ? ip = "127.0.0.1" : ip = av[6];
  if (!(pe = getprotobyname("TCP")))
    return false;
  if ((_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return false;
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(ip.c_str());
  std::cout << "Trying to connect with ip : " << ip << " and port : " << port << std::endl;
  if (connect(_fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      std::cout << "Error : Connection failed\n";
      return false;
    }
  std::cout << "Connection Success !\n";
  return true;
}

void  Client::setFD(fd_set *fd_read, fd_set *fd_write)
{
  FD_ZERO(fd_read);
  FD_ZERO(fd_write);
  FD_SET(_fd, fd_read);
  FD_SET(_fd, fd_write);
}

bool    Client::checkEndMessage()
{
  return ((_buffIn.find_last_of("\n") + 1) == _buffIn.size());
}

void	Client::getBuffInTab(const std::string &msg)
{
  static std::string            s = "";
  std::string                   delimiter = "\n";
  size_t                        pos = 0;

  s += msg;
  while ((pos = s.find(delimiter)) != std::string::npos)
    {
      _tabBuff.push_back(s.substr(0, pos));
      s.erase(0, pos + delimiter.length());
    }
}

void    Client::getLine()
{
  char  tmpBuff[4096];
  int   ret = 0;

  ret = read(_fd, tmpBuff, 4095);
  tmpBuff[ret] = '\0';
  getBuffInTab(std::string(tmpBuff));
  _buffIn += tmpBuff;
  if (checkEndMessage())
    {
      _rcvMsg = true;
    }
}

void  Client::findFDRead(fd_set *fd_read)
{
  _rcvMsg = false;
  if (FD_ISSET(_fd, fd_read))
    {
      getLine();
    }
  if (!_tabBuff.empty())
    {
      _buffIn = _tabBuff.front();
      Parser::printColored(_RED, "Server  : " + _buffIn);
      _ia.getConnection() ?
	_ia.beginConnection(_buffIn, _buffOut) :
	_ia.run(_buffIn, _buffOut);
      _tabBuff.pop_front();
    }
}

void  Client::findFDWrite(fd_set *fd_write)
{
  if (FD_ISSET(_fd, fd_write) && _buffOut.size() != 0)
    {
      write(_fd, _buffOut.c_str(), _buffOut.size());
      _buffOut.clear();
    }
}

void    Client::selectLoop()
{
  fd_set  fd_read;
  fd_set  fd_write;
  struct timeval tv;

  tv.tv_sec = 0;
  tv.tv_usec = 10000;
  while (42)
    {
      setFD(&fd_read, &fd_write);
      if ((select(_fd + 1, &fd_read, &fd_write, NULL, &tv)) == -1)
	perror("Error during execution : Exiting programm\n");
      findFDRead(&fd_read);
      findFDWrite(&fd_write);
    }
}
