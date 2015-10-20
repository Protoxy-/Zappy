#include "object/env/Ground.hh"

ObjGround::ObjGround(AObjModule const &core, int _type, int x, int y, int z) :
AObjEnv(core, _type, x, y, z)
{
  _sprt.setTexture(_res->loadImage("env/block/Ground0.png"));
  initCordValues();
}

ObjGround::~ObjGround()
{

}

void    ObjGround::initCordValues()
{
  _img.w = 72;
  _img.h = 72;
  _imgCtr.x = _img.w / 2 + 2;
  _imgCtr.y = _img.h / 2 + 12;

  _solid.x = TILE;
  _solid.y = TILE;
  _solid.w = TILE;
  _solid.h = 48;
}

void    ObjGround::update()
{
  updateBase();
}

void    ObjGround::render()
{
  renderBase();
}
