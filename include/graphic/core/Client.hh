#ifndef CLIENT_HH_
# define CLIENT_HH_

#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include "System.hh"

class	Client
{
public:
  Client();
  ~Client();
  bool		initialize(int ac, const char **av);
  bool		checkParameters(int ac, const char **av, int &);
  void		setFD(fd_set *fd_read, fd_set *fd_write);
  void		findFDRead(fd_set *fd_read);
  void		findFDWrite(fd_set *fd_write);
  bool		checkEndMessage();
  void		getLine();
  void    update();

  void    arangeCommands();

  std::string   const &getInput() const;
  std::vector<std::string>   const &getCommand() const;
  void  setOutput(std::string   const &);

private:
  std::string	_team;
  int         _fd;
  std::vector<std::string> _command;
  std::string	_buffOut;
  std::string	_buffIn;
  bool		    _rcvMsg;
  bool        _end;

  fd_set      fd_read;
  fd_set      fd_write;
};

#endif /* !CLIENT_HH_ */
