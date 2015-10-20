#include "object/player/Egg.hh"

ObjEgg::ObjEgg(AObjModule const &core, int _type, int x, int y, int z) :
  AObjPlayer(core, _type, x, y, z)
{
  _sprt.setTexture(_res->loadImage("character/Egg.png"));
  initCordValues();
}

ObjEgg::~ObjEgg()
{

}

void    ObjEgg::initCordValues()
{

  _img.w = 24;
  _img.h = 32;
  _imgCtr.x = _img.w / 2;
  _imgCtr.y = _img.h / 2 + 13;

  _solid.x = TILE;
  _solid.y = TILE;
  _solid.w = TILE;
  _solid.h = 0;
  convertToIsometric();
}

void    ObjEgg::update()
{
  updateBase();
}

void    ObjEgg::render()
{
  renderBase();
}
