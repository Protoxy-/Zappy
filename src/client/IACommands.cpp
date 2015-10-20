//
// IA.cpp for IA in /home/froehl_f/rendu/zappy/src/client
// 
// Made by Fabrice Froehly
// Login   <froehl_f@epitech.net>
// 
// Started on  Tue Jun 16 16:49:22 2015 Fabrice Froehly
// Last update Sun Jul  5 21:27:07 2015 Alexandre ARRAMON
//

#include <ostream>
#include <sstream>
#include <cstdlib>
#include "IA.hh"

const int IA::_requiredFoodPerLevel[] =
{
  10, // 0 Food Min
  15, // 1 Food Max 1j
  20, // 2 Food Max 1j
  20, // 3 Food Max 2j
  40, // 4 Food Max 2j
  40, // 5 Food Max 4j
  60, // 6 Food Max 4j
  60, // 7 Food Max 4j
  20, // 8 Food Max 4j
};

bool	IA::forkOnceInAWhile(std::string &msg)
{
  static unsigned int forky = 0;

  if (forky > 50)
    {
      getFreeSlots();
      msg = _buffToSend;
      forky = 0;
      return true;
    }
  else if (_lastCmd == CMD_CONNECT_NBR && _numClient < 1)
    {
      forkSend();
      msg = _buffToSend;
      return true;
    }
  forky++;
  return false;
}

bool	IA::refreshInventory(std::string &buffOut)
{
  static unsigned int refresh = 11;

  if (refresh > 5)
    {
      refresh = 0;
      inventaireSend();
      buffOut = _buffToSend;
      return true;
    }
  refresh++;
  return false;
}

bool	IA::pickSomeUselessRock(const std::string &msg)
{
  std::vector<std::string>      tab;
  std::string                   s = msg;
  std::string                   delimiter = ",";
  size_t                        pos = 0;
  std::string			line;
  int				i = 0;

  line = s.substr(0, s.find(delimiter));
  s = line;
  delimiter = " ";

  while ((pos = s.find(delimiter)) != std::string::npos)
    {
      tab.push_back(s.substr(0, pos));
      s.erase(0, pos + delimiter.length());
    }
  tab.push_back(s);
  if (isWordHere(line, "nourriture"))
    {
      takeObjSend("nourriture");
      return true;
    }
  for (std::map<std::string, int>::iterator it = _inventory.begin(); it != _inventory.end(); ++it)
    {
      int			nbItem = 0;
      for (std::vector<std::string>::iterator it2 = tab.begin(); it2 != tab.end(); ++it2)
	{
	  if (isWordHere(*it2, it->first))
	    nbItem++;
	}
      if (it->first != "nourriture" && isWordHere(line, it->first) && nbItem > _dataTabSubject[_lvl - 1][i])
	{
	  takeObjSend(it->first);
	  return true;
	}
      i++;
    }
  return false;
}

bool	IA::putSomeUsefullRock(const std::string &msg)
{
  std::vector<std::string>      tab;
  std::string                   s = msg;
  std::string                   delimiter = ",";
  size_t                        pos = 0;
  std::string			line;
  int				i = 0;

  line = s.substr(0, s.find(delimiter));
  s = line;
  delimiter = " ";

  while ((pos = s.find(delimiter)) != std::string::npos)
    {
      tab.push_back(s.substr(0, pos));
      s.erase(0, pos + delimiter.length());
    }
  tab.push_back(s);
  for (std::map<std::string, int>::iterator it = _inventory.begin(); it != _inventory.end(); ++it)
    {
      int			nbItem = 0;
      for (std::vector<std::string>::iterator it2 = tab.begin(); it2 != tab.end(); ++it2)
	{
	  if (isWordHere(*it2, it->first))
	    nbItem++;
	}
      if (it->first != "nourriture" && nbItem < _dataTabSubject[_lvl - 1][i] && it->second > 0)
	{
	  dropObjSend(it->first);
	  return true;
	}
      i++;
    }
  return false;
}

eReturn	IA::groundIsReady(const std::string &msg)
{
  static bool iWillSeeNextTurn = true;

  if (iWillSeeNextTurn)
    {
      iWillSeeNextTurn = false;
      look();
      return OTHER;
    }
  iWillSeeNextTurn = true;
  if (pickSomeUselessRock(msg) || putSomeUsefullRock(msg))
    {
      return FALSE;
    }
  return TRUE;
}

int	IA::getNbrPlayerOnMe(const std::string &msg)
{
  std::vector<std::string>      tab;
  std::string                   s = msg;
  std::string                   delimiter = ",";
  size_t                        pos = 0;
  std::string			line;
  int				nbPlayer = 0;

  line = s.substr(0, s.find(delimiter));
  s = line;
  delimiter = " ";
  while ((pos = s.find(delimiter)) != std::string::npos)
    {
      tab.push_back(s.substr(0, pos));
      s.erase(0, pos + delimiter.length());
    }
  tab.push_back(s);
  for (std::vector<std::string>::iterator it = tab.begin(); it != tab.end(); ++it)
    {
      if (isWordHere(*it, "joueur"))
	nbPlayer++;
    }
  return (nbPlayer);
}

eReturn	IA::checkEnoughPlayer(const std::string &msg)
{
  static bool iWillSeeNextTurn = true;
  int	player;

  if (iWillSeeNextTurn)
    {
      iWillSeeNextTurn = false;
      look();
      return OTHER;
    }
  iWillSeeNextTurn = true;
  player = getNbrPlayerOnMe(msg);
  if (player == _dataTab[_lvl - 1][DATA_PLAYER])
    return TRUE;
  else if (player < _dataTab[_lvl - 1][DATA_PLAYER])
    return FALSE_NOT_ENOUGH;
  return FALSE_TOO_MANY;
}

eRock	IA::checkEnoughRock()
{
  int	i = 0;

  for (std::map<std::string, int>::iterator it = _inventory.begin(); it != _inventory.end(); ++it)
    {
      if (_dataTab[_lvl - 1][i] > it->second && it->first != "nourriture")
	{
	  return static_cast<eRock>(i);
	}
      i++;
    }
  return ROCK_GOOD;
}

bool	IA::checkEnoughFood()
{
  static bool	lifeIsGood = false;

  if (_inventory["nourriture"] < _requiredFoodPerLevel[0])
    lifeIsGood = false;
  else if (_inventory["nourriture"] > _requiredFoodPerLevel[_lvl])
    lifeIsGood = true;
  return lifeIsGood;
}

bool	IA::isWordHere(const std::string &msg, const std::string &seek)
{
  if (msg.find(seek) != std::string::npos)
    return true;
  return false;
}

void	IA::modifOneItem(eCmdToSrv cmd, const std::string &item)
{
  int	op = 1;

  if (cmd == CMD_POSE)
    op = -op;
  for (std::map<std::string, int>::iterator it = _inventory.begin(); it != _inventory.end(); ++it)
    {
      if (isWordHere(it->first, item))
	it->second = it->second + op;
    }
}

void	IA::fillOneCase(std::string line)
{
  std::vector<std::string>      tab;
  std::string                   s = line;
  std::string                   delimiter = " ";
  size_t                        pos = 0;

  while ((pos = s.find(delimiter)) != std::string::npos)
    {
      tab.push_back(s.substr(0, pos));
      s.erase(0, pos + delimiter.length());
    }
  tab.push_back(s);
  for (std::map<std::string, int>::iterator it = _inventory.begin(); it != _inventory.end(); ++it)
    {
      if (isWordHere(tab[0], it->first))
	       it->second = atoi(tab[1].c_str());
    }
}

void	IA::modifAllItem(const std::string &msg)
{
  std::vector<std::string>	tab;
  std::string			s = msg;
  std::string			delimiter = ",";
  size_t			pos = 0;

  while ((pos = s.find(delimiter)) != std::string::npos)
    {
      tab.push_back(s.substr(0, pos));
      s.erase(0, pos + delimiter.length());
    }
  tab.push_back(s);
  for (unsigned int i = 0; i < tab.size(); i++)
    fillOneCase(tab[i]);
}

void	IA::updateInventory(eCmdToSrv cmd, const std::string &msg)
{
  if (cmd == CMD_PREND || cmd == CMD_POSE)
    modifOneItem(cmd, msg);
  else
    {
      modifAllItem(msg);
    }
}

void	IA::updateLvl(const std::string &msg)
{
  std::vector<std::string>	tab;
  std::string			s = msg;
  std::string			delimiter = " ";
  size_t			pos = 0;

  while ((pos = s.find(delimiter)) != std::string::npos)
    s.erase(0, pos + delimiter.length());
  _lvl = atoi(s.c_str());
}

void	IA::refreshPlayerInFrontOfMe()
{
  std::vector<std::string>	tab;
  std::string			s = _lastVoir;
  std::string			delimiter = ",";
  size_t			pos = 0;

  while ((pos = s.find(delimiter)) != std::string::npos)
    {
      tab.push_back(s.substr(0, pos));
      s.erase(0, pos + delimiter.length());
    }
  tab.push_back(s);
  if (tab.size() > 2 && isWordHere(tab[2], "joueur"))
    _playerInFrontOfMe = true;
  else
    _playerInFrontOfMe = true;
}

void	IA::refreshInfo(const std::string &msgRcv)
{
  if (isWordHere(msgRcv, "niveau actuel"))
    {
      _lastCmd = CMD_INCANTATION_END;
      updateLvl(msgRcv);
    }
  if (isWordHere(msgRcv, "elevation en cours"))
    _lastCmd = CMD_INCANTATION_BEGIN;
  if (msgRcv.find("mort", 0) != std::string::npos)
    exit(0);
  if (isWordHere(msgRcv, "message"))
    {
      if (_parser.getSoundDirection(msgRcv, _team, _lvl, "lfp") != -1)
	{
	  _lastBroadcast = msgRcv;
	}
      else
	return ;
    }
  if (_lastCmd == CMD_NONE)
    return ;
  if ((_lastCmd == CMD_PREND || _lastCmd == CMD_POSE) && isWordHere(msgRcv,"ok"))
    {
      updateInventory(_lastCmd, _lastObj);
    }
  if (_lastCmd == CMD_INV)
    {
      updateInventory(_lastCmd, msgRcv);
    }
  if (_lastCmd == CMD_CONNECT_NBR)
    {
      _numClient = atoi(msgRcv.c_str());
    }
  if (_lastCmd == CMD_INCANTATION_BEGIN)
    {
      if (isWordHere(msgRcv, "niveau actuel"))
	{
	  _lastCmd = CMD_INCANTATION_END;
	  updateLvl(msgRcv);
	}
      else if (isWordHere(msgRcv, "ko"))
	_lastCmd = CMD_INCANTATION_END;
    }
  if (_lastCmd == CMD_VOIR)
    {
      _lastVoir = msgRcv;
      refreshPlayerInFrontOfMe();
    }
}

void	IA::parsePos(const std::string &msg)
{
  int	pos = 0;
  std::stringstream os;

  if (!(pos = msg.find_first_of(" ")))
    return ;
  os.str(msg.substr(0, pos));
  os >> _x;
  os.clear();
  os.str(msg.substr(pos + 1, msg.size()));
  os >> _y;
}

void	IA::beginConnection(const std::string &in, std::string &out)
{
  if (_beginConnection == 2)
    out = _team + "\n";
  else if (_beginConnection == 1)
    {
      if (isWordHere(in, "ko"))
	{
	  std::cout << "Erreur : Mauvais nom de team\n";
	  exit(1);
	}
      std::stringstream os;
      os.str(in);
      os >> _numClient;
    }
  else
    parsePos(in);
  _beginConnection--;
}

void	IA::welcome()
{
  _parser.printColored(_BLU, "Client  : Vous avez reçu welcome et vous envoyez le nom de votre team");
  _buffToSend = _team;
  _buffToSend += "\n";
}

void	IA::walk()
{
  if (!_searchingPlayer && _playerInFrontOfMe)
    {
      right();
    }
  _parser.printColored(_BLU, "Client  : Vous avancez");
  _buffToSend = "avance\n";
  _lastCmd = CMD_NONE;
}

void	IA::left()
{
  _parser.printColored(_BLU, "Client  : Vous allez à gauche");
  _buffToSend = "gauche\n";
  _lastCmd = CMD_NONE;
}

void	IA::right()
{
  _parser.printColored(_BLU, "Client  : Vous allez à droite");
  _buffToSend = "droite\n";
  _lastCmd = CMD_NONE;
}

void	IA::forkSend()
{
  _parser.printColored(_BLU, "Client  : Vous avez pondu un oeuf");
  _buffToSend = "fork\n";
  _lastCmd = CMD_NONE;
}

void	IA::broadcast(std::string msg)
{
  _parser.printColored(_BLU, "Client  : Vous avez fait un broadcast");
  _buffToSend = "broadcast " + _team + " " + _parser.intToStr(_lvl) + " " + msg + "\n";
  _lastCmd = CMD_BROADCAST;
}

void	IA::look() // set map que l'on voit
{
  _parser.printColored(_BLU, "Client  : Vous avez fait un look");
  _buffToSend = "voir\n";
  _lastCmd = CMD_VOIR;
}

void	IA::inventaireSend() // set inventory map + getLife
{
  _parser.printColored(_BLU, "Client  : Vous avez set l'inventaire");
  _buffToSend = "inventaire\n";
  _lastCmd = CMD_INV;
}

void	IA::takeObjSend(std::string obj) // envoyer au serveur
{
  _parser.printColored(_BLU, "Client  : Vous envoyez la commande take");
  _buffToSend = "prend ";
  _buffToSend += obj;
  _buffToSend += "\n";
  _lastCmd = CMD_PREND;
  _lastObj = obj;
}

void	IA::takeObjOk() // traiter si (lastmethod == takeObjSend && buffRcv == ok)
{
  _parser.printColored(_BLU, "Client  : Vous avez pris un objet");
}

void	IA::dropObjSend(std::string obj)
{
  _parser.printColored(_BLU, "Client  : Vous envoyez la commande drop");
  _buffToSend = "pose ";
  _buffToSend += obj;
  _buffToSend += "\n";
  _lastObj = obj;
  _lastCmd = CMD_POSE;
}

void	IA::dropObjOk()
{
  _parser.printColored(_BLU, "Client  : Vous avez drop un objet");
}

void	IA::death()
{
  _parser.printColored(_BLU, "Client  : Vous êtes mort");
  exit(1);
}

void	IA::expulse()
{
  _parser.printColored(_BLU, "Client  : Vous avez expulsé des gens");
  _buffToSend = "expulse\n";
}

void	IA::getFreeSlots()
{
  _buffToSend = "connect_nbr\n";
  _lastCmd = CMD_CONNECT_NBR;
  _parser.printColored(_BLU, "Client  : Vous avez demandé le nombre restant de joueurs");
}

void	IA::incantation()
{
  _buffToSend = "incantation\n";
  _lastCmd = CMD_INCANTATION_BEGIN;
  _parser.printColored(_BLU, "Client  : Vous avez commencé l'incantation");
}

bool	IA::thereIsItemInFrontOfMe(const std::string &msg, const std::string &item)
{
  if (msg.find(item) != std::string::npos)
    return true;
  return false;
}

bool	IA::thereIsItemOnMe(const std::string &msg, const std::string &item)
{
  int	food;
  int	firstCase;

  food = msg.find(item);
  firstCase = msg.find(",");
  if (food != -1 && firstCase != -1 && food < firstCase)
    return true;
  return false;
}

bool	IA::checkBeforeMove(int &goTheSameWay, int &nbOfTurn, bool &iWillSeeNextTurn, eNextTurn &nextTurn)
{
  if (nextTurn == TURN_LEFT)
    {
      left();
      nextTurn = NONE;
      return true;
    }
  else if (nextTurn == TURN_RIGHT)
    {
      right();
      nextTurn = NONE;
      return true;
    }

  if (goTheSameWay > (std::rand() % 3 + 4))
    {
      left();
      goTheSameWay = 0;
      return true;
    }
  if (iWillSeeNextTurn)
    {
      if (nbOfTurn == 2)
      	{
      	  left();
      	  nbOfTurn++;
      	}
      else
       	{
	  look();
	  iWillSeeNextTurn = false;
	}
      return true;
    }
  return false;
}

bool		IA::badPlacedItem(eNextTurn &nextTurn, const std::string &msg, const std::string &item)
{
  std::vector<std::string>      tab;
  std::string s = msg;
  std::string delimiter = ",";
  size_t pos = 0;

  while ((pos = s.find(delimiter)) != std::string::npos)
    {
      tab.push_back(s.substr(0, pos));
      s.erase(0, pos + delimiter.length());
    }
  tab.push_back(s);
  for (unsigned int i = 0; i < tab.size(); i++)
    {
      if (tab[i].find(item) != std::string::npos)
	{
	  if (i == 1 || i == 4 || i == 9 || i == 16 || i == 25 || i == 36 || i == 49 || i == 64)
	    nextTurn = TURN_LEFT;
	  else if (i == 3 || i == 8 || i == 15 || i == 24 || i == 35 || i == 48 || i == 63 || i == 80)
	    nextTurn = TURN_RIGHT;
	  else
	    nextTurn = NONE;
	  return true;
	}
    }
  nextTurn = NONE;
  return false;
}

void			IA::searchAnyItem(const std::string &msg, const std::string &item)
{
  static eNextTurn	nextTurn = NONE;
  static int		goTheSameWay = 0;
  static int		nbOfTurn = 0;
  static bool		iWillSeeNextTurn = true;

  if (checkBeforeMove(goTheSameWay, nbOfTurn, iWillSeeNextTurn, nextTurn))
    return ;
  if (thereIsItemInFrontOfMe(msg, item))
    {
      if (thereIsItemOnMe(msg, item))
	{
	  goTheSameWay = 0;
	  takeObjSend(item);
	}
      else if (getNbrPlayerOnMe(msg) > 1)
	{
	  if (std::rand() % 2)
	    {
	      nbOfTurn++;
	      left();
	    }
	  else
	    {
	      goTheSameWay++;
	      walk();
	    }
	  iWillSeeNextTurn = true;
	  return;
	}
      else if (badPlacedItem(nextTurn, msg, item))
	{
	  nbOfTurn = 0;
	  walk();
	}
      else
      	{
      	  goTheSameWay++;
      	  walk();
      	}
      iWillSeeNextTurn = true;
      nbOfTurn = 0;
      return ;
    }
  else
    {
      if (nbOfTurn >= (std::rand() % 3 + 2))
	{
	  walk();
	  goTheSameWay++;
	  nbOfTurn = 0;
	  iWillSeeNextTurn = true;
	}
      else
	{
	  iWillSeeNextTurn = true;
	  left();
	  nbOfTurn++;
	}
    }
}

void		IA::searchFood(const std::string &msg)
{
  searchAnyItem(msg, "nourriture");
}

void	IA::searchRock(const std::string &msg, eRock rock)
{
  if (rock == ROCK_LINEMATE)
    searchAnyItem(msg, "linemate");
  else if (rock == ROCK_DERAUMERE)
    searchAnyItem(msg, "deraumere");
  else if (rock == ROCK_SIBUR)
    searchAnyItem(msg, "sibur");
  else if (rock == ROCK_MENDIANE)
    searchAnyItem(msg, "mendiane");
  else if (rock == ROCK_PHIRAS)
    searchAnyItem(msg, "phiras");
  else if (rock == ROCK_THYSTAME)
    searchAnyItem(msg, "thystame");
}
