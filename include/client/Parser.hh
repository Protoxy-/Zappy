//
// IA.hh for IA in /home/froehl_f/rendu/zappy/include/client
// 
// Made by Fabrice Froehly
// Login   <froehl_f@epitech.net>
// 
// Started on  Tue Jun 16 16:46:33 2015 Fabrice Froehly
// Last update Fri Jul  3 20:04:59 2015 Fabrice Froehly
//

#ifndef PARSER_HH_
# define PARSER_HH_

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

# define _RED "\033[31m"
# define _GRE "\033[32m"
# define _YEL "\033[33m"
# define _BLU "\033[34m"
# define _DEF "\033[39m"

class	Parser
{
public:
  Parser();
  ~Parser();
  static void printColored(const std::string &, const std::string &);
  int strToInt(const std::string &);
  std::string intToStr(int);
  int getSoundDirection(const std::string & msg, const std::string & team, int lvl, const std::string & cmd);
private:
  bool checkIfCommandIsForMe(const std::string & msg, const std::string team, int lvl, const std::string & cmd);
  int cutSoundDirection(const std::string & msg);
};

#endif /* !PARSER_HH_ */
