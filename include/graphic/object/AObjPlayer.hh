#ifndef AOBJPLAYER_HH_
#define AOBJPLAYER_HH_

#include "System.hh"
#include "object/AObject.hh"
#include "object/AObjItem.hh"

class AObjPlayer : public AObject
{
protected:
  std::vector<size_t> _inventory;

  std::string  _teamName;
  size_t       _id;
  size_t       _dir;
  size_t       _angle;

  size_t       _level;

  bool         _dead;

  CordRect     _movePos;

public:
  AObjPlayer(AObjModule const &core, int, int, int, int);
  virtual ~AObjPlayer();

  virtual void update();
  virtual void render();

  void  setTeamName(std::string const &);
  std::string const &getTeamName() const;

  void  setId(size_t);
  size_t  getId() const;

  void  setLevel(size_t);
  size_t  getLevel() const;

  void  setDir(size_t);
  size_t  getDir() const;

  void  setMove(int, int, int);

  void  setMovePos(int, int);
  CordRect const &getMovePos() const;

  void  setInventory(size_t, size_t);
  std::vector<size_t> const &getInventory() const;

  void  setDead();
  bool  getDead() const;

};

#endif
