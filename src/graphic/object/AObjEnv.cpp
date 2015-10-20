#include "object/AObjEnv.hh"

AObjEnv::AObjEnv(AObjModule const &core, int type, int x, int y, int z) :
  AObject(core, type)
{
  _layer = _cord->get("layer.w") - 1;
  _pos.x = x * TILE;
  _pos.y = y * TILE;
  _pos.w = z;
}

AObjEnv::~AObjEnv()
{
}

void AObjEnv::update()
{

}

void AObjEnv::render()
{

}
