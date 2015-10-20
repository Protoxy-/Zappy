//
// IA.hh for IA in /home/froehl_f/rendu/zappy/include/client
// 
// Made by Fabrice Froehly
// Login   <froehl_f@epitech.net>
// 
// Started on  Tue Jun 16 16:46:33 2015 Fabrice Froehly
// Last update Sun Jul  5 21:30:06 2015 Alexandre ARRAMON
//

#ifndef IA_HH_
# define IA_HH_

#include <map>
#include <string>
#include <iostream>
#include <list>
#include "Parser.hh"
#include <cstdlib>
#include <ctime>

enum	eNextTurn
  {
    NONE = 0,
    TURN_LEFT,
    TURN_RIGHT
  };

enum	eCmdToSrv
  {
    CMD_NONE = 0,
    CMD_INV,
    CMD_PREND,
    CMD_POSE,
    CMD_VOIR,
    CMD_INCANTATION_BEGIN,
    CMD_INCANTATION_END,
    CMD_CONNECT_NBR,
    CMD_BROADCAST
  };

enum	eRock
  {
    ROCK_DERAUMERE,
    ROCK_LINEMATE,
    ROCK_MENDIANE,
    ROCK_GOOD,
    ROCK_PHIRAS,
    ROCK_SIBUR,
    ROCK_THYSTAME,
  };

enum	eDataTab
  {
    DATA_DERAUMERE = 0,
    DATA_LINEMATE,
    DATA_MENDIANE,
    DATA_PLAYER,
    DATA_PHIRAS,
    DATA_SIBUR,
    DATA_THYSTAME
  };

enum	eReturn
  {
    OTHER = 0,
    TRUE,
    FALSE,
    FALSE_NOT_ENOUGH,
    FALSE_TOO_MANY
  };

class	IA
{
public:
  IA();
  ~IA();
  void	run(const std::string &, std::string &);
  void	setTeam(const std::string &team){_team = team;};
  int getConnection()const{ return _beginConnection; }
  void beginConnection(const std::string &, std::string &);

private:
  bool forkOnceInAWhile(std::string &);

  eReturn groundIsReady(const std::string &);
  bool pickSomeUselessRock(const std::string &);
  bool putSomeUsefullRock(const std::string &);

  eReturn checkEnoughPlayer(const std::string &);
  int getNbrPlayerOnMe(const std::string &);

  void searchAnyItem(const std::string &, const std::string &);

  void searchRock(const std::string &, eRock);

  eRock checkEnoughRock();

  bool checkEnoughFood();

  bool refreshInventory(std::string &);

  void refreshPlayerInFrontOfMe();
  void refreshInfo(const std::string &);
  void updateLvl(const std::string &);
  void updateInventory(eCmdToSrv, const std::string &);
  void modifOneItem(eCmdToSrv, const std::string &);
  void modifAllItem(const std::string &);
  void fillOneCase(std::string line);

  void initInventory();
  void initDataTab();

  bool isWordHere(const std::string &, const std::string &);

  bool badPlacedItem(eNextTurn &, const std::string &, const std::string &);
  bool checkBeforeMove(int &, int &, bool &, eNextTurn &);
  void searchFood(const std::string &);
  void searchPlayer();
  void moveToSound(int direction);
  bool thereIsItemInFrontOfMe(const std::string &, const std::string &);
  bool thereIsItemOnMe(const std::string &, const std::string &);

  void parsePos(const std::string &);
  void welcome();
  void walk();
  void left();
  void right();
  void forkSend();
  void broadcast(std::string);

  void look(); // set map que l'on voit
  void setInventory(); // set inventory map + getLife
  void inventaireSend(); // send inventaire

  void incantation();

  void takeObjSend(std::string); // envoyer au serveur
  void takeObjOk(); // traiter si (lastmethod == takeObjSend && buffRcv == ok)

  void dropObjSend(std::string);
  void dropObjOk();

  void death();
  void expulse();

  void getFreeSlots();

  Parser      			_parser;
  std::map<std::string, int>	_inventory;
  std::string 			_buffToSend;
  std::string			_team;
  int				_beginConnection;
  int				_numClient;
  int				_x;
  int				_y;
  int				_lvl;
  std::string			_lastObj;
  std::string			_lastVoir;
  std::string			_lastBroadcast;
  eCmdToSrv			_lastCmd;
  bool				_searchingPlayer;
  bool				_playerInFrontOfMe;
  std::vector<std::vector<int>> _dataTab;
  std::vector<std::vector<int>> _dataTabSubject;
  static void (IA::* const      _movements[9])();
  static const int              _requiredFoodPerLevel[];
};

#endif /* !IA_HH_ */
