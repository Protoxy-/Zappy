//
// IA.cpp for IA in /home/froehl_f/rendu/zappy/src/client
// 
// Made by Fabrice Froehly
// Login   <froehl_f@epitech.net>
// 
// Started on  Tue Jun 16 16:49:22 2015 Fabrice Froehly
// Last update Sun Jul  5 21:27:35 2015 Alexandre ARRAMON
//

#include <unistd.h>
#include "IA.hh"

void (IA::* const IA::_movements[9])() =
{
  &IA::walk,
  &IA::walk,
  &IA::walk,
  &IA::left,
  &IA::left,
  &IA::right,
  &IA::right,
  &IA::right,
  &IA::walk
};

IA::IA():
  _buffToSend(""),
  _beginConnection(2),
  _x(0),
  _y(0),
  _lvl(1),
  _lastObj(""),
  _lastVoir(""),
  _lastBroadcast(""),
  _lastCmd(CMD_NONE),
  _searchingPlayer(false),
  _playerInFrontOfMe(false)
{
  initInventory();
  initDataTab();
  std::srand(std::time(0));
}

IA::~IA() {}

// search for nearby players until amount is reached
// broadcast format : lfp [level]

void	IA::moveToSound(int direction)
{
  if (direction == 0)
    {
      _parser.printColored(_GRE, "IA : CAUSETTE DIR = 000000");
      broadcast("lfp");
    }
  else
    {
      (this->*_movements[direction])();
    }
}

void	IA::searchPlayer()
{
  int direction = _parser.getSoundDirection(_lastBroadcast, _team, _lvl, "lfp");
  if (direction >= 0)
    {
      moveToSound(direction);
      _lastBroadcast = "";
    }
  else
    {
      _parser.printColored(_GRE, "IA : CAUSETTE DIR = -----1");
      broadcast("lfp");
    }
}

void	IA::initDataTab()
{
  _dataTab =
    {
      {0, 1, 0, 1, 0, 0, 0},
      {1, 1, 0, 2, 0, 1, 0},
      {1, 1, 0, 2, 1, 1, 0},
      {1, 1, 1, 4, 1, 1, 0},
      {1, 1, 1, 4, 0, 1, 0},
      {1, 1, 0, 6, 1, 1, 0},
      {1, 1, 1, 6, 1, 1, 0},
    };

  _dataTabSubject =
    {
      {0, 1, 0, 1, 0, 0, 0},
      {1, 1, 0, 2, 0, 1, 0},
      {0, 2, 0, 2, 2, 1, 0},
      {1, 1, 0, 4, 1, 2, 0},
      {2, 1, 3, 4, 0, 1, 0},
      {2, 1, 0, 6, 1, 3, 0},
      {2, 2, 2, 6, 2, 2, 1},
    };
}

void	IA::initInventory()
{
  _inventory =
    {
      {"deraumere", 0},
      {"linemate", 0},
      {"mendiane", 0},
      {"nourriture", 10},
      {"phiras", 0},
      {"sibur", 0},
      {"thystame", 0}
    };
}

void	IA::run(const std::string &buffRcv, std::string &buffToSend)
{
  static_cast<void>(buffRcv);
  static bool jePose = false;
  eRock rock;
  eReturn checkPlayer;
  eReturn ground;
  static unsigned int		incantaKo = 0;

  if (_lastCmd == CMD_INCANTATION_BEGIN && isWordHere(buffRcv, "ko"))
    {
      look();
      buffToSend = _buffToSend;
      return;
    }
  if (incantaKo <= 1 && isWordHere(buffRcv, "ko"))
    {
      _parser.printColored(_YEL, "IA::Run : incantaKO return");
      return ;
    }
  if (isWordHere(buffRcv, "ko"))
    {
      look();
      buffToSend = _buffToSend;
      return ;
    }
  refreshInfo(buffRcv);
  if (isWordHere(buffRcv, "message"))
    return ;
  if (_lastCmd == CMD_INCANTATION_END)
    {
      inventaireSend();
      buffToSend = _buffToSend;
      return ;
    }
  if (_lastCmd == CMD_INCANTATION_BEGIN)
    return ;
  if (isWordHere(buffRcv, "niveau actuel"))
    return ;
  if (refreshInventory(buffToSend))
    return ;
  if (forkOnceInAWhile(buffToSend))
    return ;
  incantaKo++;

  if ((_buffToSend == "voir\n" && isWordHere(buffRcv, "ok")) || (_buffToSend == "avance\n" && !isWordHere(buffRcv, "ok")))
    {
      return ;
    }
  if (!jePose && !checkEnoughFood())
    {
      _parser.printColored(_YEL, "IA::Run : Je cherche de la food");
      _searchingPlayer = false;
      searchFood(_lastVoir);
    }
  else
    {
      _parser.printColored(_YEL, "IA::Run : J'ai assez de food");
      if (jePose || ((rock = checkEnoughRock()) == ROCK_GOOD))
        {
          if ((checkPlayer = checkEnoughPlayer(buffRcv)) == OTHER)
            {
	      _parser.printColored(_YEL, "IA::Run : iWillSeeNextTurn");
              buffToSend = _buffToSend;
              return ;
            }
          else if (checkPlayer == TRUE)
            {
	      jePose = true;
	      _parser.printColored(_YEL, "IA::Run : Le nombre de players est bon");
              if ((ground = groundIsReady(buffRcv)) == TRUE)
                {
		  _searchingPlayer = false;
		  _parser.printColored(_YEL, "IA::Run : Incantation Go");
		  incantaKo = 0;
                  incantation();
		  jePose = false;
                }
            }
          else
            {
	      _parser.printColored(_YEL, "IA::Run : Je cherche des players");
	      if (checkPlayer == FALSE_NOT_ENOUGH)
		{
		  _searchingPlayer = true;
		  searchPlayer();
		}
	      if (checkPlayer == FALSE_TOO_MANY)
		walk();
	      jePose = false;
            }
        }
      else
	{
	  _parser.printColored(_YEL, "IA::Run : Je cherche de la rock : " + rock);
	  _searchingPlayer = false;
	  searchRock(buffRcv, rock);
	}
    }
  _parser.printColored(_YEL, "IA::Run : Je send : " + _buffToSend);
  buffToSend = _buffToSend;
}
