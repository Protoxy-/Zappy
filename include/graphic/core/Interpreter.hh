#ifndef INTERPRETER_HH_
#define INTERPRETER_HH_

#include "engine/GraphicCore.hh"
#include "core/MapManager.hh"
#include "object/ObjIncludes.hh"

class   Interpreter : public GraphicCore
{
  MapManager                          *_map;

  std::map<std::string, void (Interpreter::*)()> _command;

  std::vector<std::string> _arg;
  std::string              _line;

  int                      _eggId;

public:
  Interpreter(GraphicCore const &, MapManager *);
  ~Interpreter();

  void update(std::vector<std::string> const &);

  void    mapSize();
  void    contentCase();
  void    teamName();
  void    newPlayer();
  void    playerPosition();
  void    playerLevel();
  void    playerInventory();
  void    playerExpulse();
  void    playerBroadcast();
  void    firstIncantation();
  void    endIncantation();
  void    playerEgg();
  void    playerThrow();
  void    playerTake();
  void    playerDead();
  void    newEgg();
  void    eggBirth();
  void    eggConnect();
  void    eggDead();
  void    getTimeUnit();
  void    setTimeUnit();
  void    endGame();
  void    message();
  void    unknow();
  void    inputError();

};

#endif
