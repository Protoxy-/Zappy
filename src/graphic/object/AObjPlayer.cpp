#include "object/AObjPlayer.hh"

AObjPlayer::AObjPlayer(AObjModule const &core, int type, int x, int y, int z) :
  AObject(core, type)
{
  _layer = _cord->get("layer.w");

  _pos.x = x * TILE;
  _pos.y = y * TILE;
  _pos.w = z;
  _id = 0;
  for (int i = 0; i < 7; i++)
    _inventory.push_back(0);

  _movePos.x = 0;
  _movePos.y = 0;
  _dead = false;
  _dir = 0;
  _angle = 0;
}

AObjPlayer::~AObjPlayer()
{

}

void AObjPlayer::update()
{

}

void AObjPlayer::render()
{
}


void  AObjPlayer::setTeamName(std::string const &name)
{
  _teamName = name;
}

std::string const &AObjPlayer::getTeamName() const
{
  return _teamName;
}

void  AObjPlayer::setId(size_t id)
{
  _id = id;
}

size_t  AObjPlayer::getId() const
{
  return _id;
}

void  AObjPlayer::setDir(size_t dir)
{
  _dir = dir;
}

size_t  AObjPlayer::getDir() const
{
  return _dir;
}


void  AObjPlayer::setLevel(size_t level)
{
  _level = level;
}

size_t  AObjPlayer::getLevel() const
{
  return _level;
}

void  AObjPlayer::setMove(int x, int y, int o)
{
  _movePos.x = x * TILE;
  _movePos.y = y * TILE;
  _dir = o;
}


void  AObjPlayer::setMovePos(int x, int y)
{
  _movePos.x = x * TILE;
  _movePos.y = y * TILE;
}

CordRect const &AObjPlayer::getMovePos() const
{
  return _movePos;
}

void  AObjPlayer::setInventory(size_t type, size_t nb)
{
  _inventory[type] = nb;
}

std::vector<size_t> const &AObjPlayer::getInventory() const
{
  return _inventory;
}

void  AObjPlayer::setDead()
{
  _dead = true;
}

bool  AObjPlayer::getDead() const
{
  return _dead;
}
