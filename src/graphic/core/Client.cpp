#include "core/Client.hh"

Client::Client()
{
  _buffOut = "GRAPHIC\r\n";
  _rcvMsg = false;
}

Client::~Client() {}

bool	Client::checkParameters(int ac, const char **av, int &port)
{
  if ((ac < 3)
      || (ac >= 3 && (std::string(av[1]).compare("-p") != 0))
      || (ac >= 4 && (std::string(av[1]).compare("-p") != 0 || std::string(av[3]).compare("-h") != 0)))
    {
      std::cout << "Usage : ./client [-p] [Port] ([-h] [IP])" << std::endl;
      return false;
    }
  if (ac >= 3)
    port = std::atoi(av[2]);
  else
    {
      std::cout << "Couldn't set the port\n";
      return false;
    }
  return true;
}

bool      Client::initialize(int ac, const char **av)
{
  struct	sockaddr_in  s_in;
  struct	protoent *pe;
  int		port;
  std::string	ip;

  if (!checkParameters(ac, av, port))
    return false;
  ac < 3 ? ip = "127.0.0.1" : ip = av[4];
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

void    Client::getLine()
{
  char  tmpBuff[4096];
  int   ret = 0;

  ret = read(_fd, tmpBuff, 4095);
  tmpBuff[ret] = '\0';
  _buffIn += tmpBuff;
  if (checkEndMessage())
  {
    _rcvMsg = true;
    _end = true;
  }
}

void  Client::findFDRead(fd_set *fd_read)
{
  if (_rcvMsg == true)
    _buffIn.clear();
  _rcvMsg = false;
  if (FD_ISSET(_fd, fd_read))
  {
    _end = false;
    getLine();
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

void    Client::arangeCommands()
{
  std::string line;
  size_t         i;

  if (!_command.empty())
    _command.erase(_command.begin(), _command.end());
  for (i = 0; i < _buffIn.size(); i++)
  {
    if (_buffIn[i] != '\n')
      line += _buffIn[i];
    else
    {
      _command.push_back(line);
      line = "";
    }
  }
}

void    Client::update()
{
  int   i;
  struct timeval tv;

  tv.tv_sec = 0;
  tv.tv_usec = 10000;
  _end = true;
  for (i = 0; i < 1000000; i++)
  {
    setFD(&fd_read, &fd_write);
    if ((select(_fd + 1, &fd_read, &fd_write, NULL, &tv)) == -1)
    perror("Error during execution : Exiting programm\n");
    findFDRead(&fd_read);
    findFDWrite(&fd_write);
    _buffOut = "";
    if (_end == true)
      break;
  }
  if (i == 1000000)
    std::cout << "Warning: condition end is not reach on data income from server !" << std::endl;
  arangeCommands();
}

void  Client::setOutput(std::string const &out)
{
  _buffOut = out;
}

std::string   const &Client::getInput() const
{
  return _buffIn;
}

std::vector<std::string>   const &Client::getCommand() const
{
  return _command;
}
