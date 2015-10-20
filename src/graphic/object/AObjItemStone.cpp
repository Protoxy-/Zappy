#include "object/AObjItemStone.hh"

AObjItemStone::AObjItemStone(AObjModule const &core, int type, int x, int y, int z) :
  AObjItem(core, type, x, y, z)
{
  initCordValues();
}

AObjItemStone::~AObjItemStone()
{

}

void    AObjItemStone::initCordValues()
{
  _img.w = 24;
  _img.h = 24;
  _imgCtr.x = _img.w / 2;
  _imgCtr.y = _img.h / 2 + 13;

  _solid.x = TILE;
  _solid.y = TILE;
  _solid.w = TILE;
  _solid.h = 8;
}

void AObjItemStone::update()
{

}

void AObjItemStone::render()
{

}
