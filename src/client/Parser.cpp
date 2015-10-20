//
// Parser.cpp for Parser in /home/froehl_f/rendu/zappy/src/client
// 
// Made by Fabrice Froehly
// Login   <froehl_f@epitech.net>
// 
// Started on  Tue Jun 16 16:49:22 2015 Fabrice Froehly
// Last update Sun Jul  5 21:28:02 2015 Alexandre ARRAMON
//

#include <vector>
#include <cstdlib>
#include "Parser.hh"

Parser::Parser(){}

Parser::~Parser(){}

void Parser::printColored(const std::string & color, const std::string & msg)
{
	std::cout << color << msg << _DEF << std::endl;
}

int Parser::strToInt(const std::string & str)
{
  std::stringstream ss( str );
  int i;
  ss >> i;
  return ss.fail() ? 0 : i;
}

std::string Parser::intToStr(int nb)
{
  std::stringstream ss;
  ss << nb;
  return ss.str();
}

bool Parser::checkIfCommandIsForMe(const std::string & msg, const std::string team, int lvl, const std::string & cmd)
{
  if (msg == "" || msg.size() < team.size() + 3 + cmd.size())
    return false;
  if (msg.compare(0, team.size(), team) != 0)
    return false;
  if (msg.compare(team.size() + 1, 1, intToStr(lvl)) != 0)
    return false;
  if (msg.compare(team.size() + 3, cmd.size(), cmd) != 0)
    return false;
  return true;
}

int Parser::cutSoundDirection(const std::string & msg)
{
  if (msg.size() < 2)
    return -1;
  int direction = strToInt(msg.substr(0, 1));
  return (direction > 0 && direction < 9) ? direction : -1;
}

int Parser::getSoundDirection(const std::string & msg, const std::string & team, int lvl, const std::string & cmd)
{
  if (msg == "" && msg.compare(0, 8, "message ") != 0)
    return -1;
  std::string tmp = msg.substr(8, msg.size() - 8);
  int direction = cutSoundDirection(tmp);
  if (direction == -1 || !(checkIfCommandIsForMe( (tmp.substr(2, msg.size() - 2)) , team, lvl, cmd)))
    return -1;
  return direction;
}
