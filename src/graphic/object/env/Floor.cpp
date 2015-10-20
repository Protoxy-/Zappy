#include "object/env/Floor.hh"

ObjFloor::ObjFloor(AObjModule const &core, int _type, int x, int y, int z) :
  AObjEnv(core, _type, x, y, z)
{
  _sprt.setTexture(_res->loadImage("env/floor/Stone1.png"));
  initCordValues();
}

ObjFloor::~ObjFloor()
{

}

void    ObjFloor::initCordValues()
{
  _colorBase.r = 224 + (rand() % 32);
  _colorBase.b = 224 + (rand() % 32);
  _colorBase.g = 224 + (rand() % 32);
  _sprt.setColor(_colorBase);

  _img.w = 96;
  _img.h = 144;
  _imgCtr.x = _img.w / 2;
  _imgCtr.y = _img.h / 2 + 8;

  _solid.x = TILE;
  _solid.y = TILE;
  _solid.w = TILE;
  _solid.h = 8;
}


void    ObjFloor::update()
{
  updateBase();
  if (_stp % 5 == 0)
    checkMousePos();
  _stp++;
}

void    ObjFloor::render()
{
  renderBase();
}

void    ObjFloor::checkMousePos()
{
  CordRect  chk;
  CordRect  pos;
  CordRect  vec;
  CordRect  win;

  convertToLayer();
  chk.x = _disp.x - (_cord->get("camera.x") - (_cord->get("win.w") / 2));
  chk.y = _disp.y - (_cord->get("camera.y") - (_cord->get("win.h") / 2));
  chk.x += _win->getPosition().x;
  chk.y += _win->getPosition().y + TILE / 2;
  _color = _colorBase;
  if (_cord->get("selCase.x") == _pos.x / TILE && _cord->get("selCase.y") == _pos.y / TILE)
  {
    _color.r = 64;
    _color.g = 128;
  }
  _sprt.setColor(_color);

  win.w = (_cord->get("win.w"));
  win.h = (_cord->get("win.h"));
  win.x = (win.w * ((48 - _cord->get("zoom")) + 48) / 48);
  win.y = (win.h * ((48 - _cord->get("zoom")) + 48) / 48);
  pos.x = _input->getMousePos().x;
  pos.y = _input->getMousePos().y;

  if (pos.x >= chk.x && pos.x <= chk.x + TILE)
  if (pos.y >= chk.y && pos.y <= chk.y + TILE / 2)
  {
    vec.x = ((pos.y - chk.y) - (TILE / 4)) * (TILE / 2) / (TILE / 4);
    vec.y = ((pos.x - chk.x) - (TILE / 2)) * (TILE / 4) / (TILE / 2);
    if (vec.x < 0)
      vec.x *= -1;
    if (vec.y < 0)
      vec.y *= -1;
    if (pos.x >= chk.x + vec.x && pos.x <= chk.x + (TILE) - vec.x)
    if (pos.y >= chk.y + vec.y && pos.y <= chk.y + (TILE / 2) - vec.y)
    {
    _cord->set("select.x", _pos.x / TILE);
    _cord->set("select.y", _pos.y / TILE);
    _color.a = 192;
    _color.r = 64;
    _sprt.setColor(_color);
    }
  }
}
