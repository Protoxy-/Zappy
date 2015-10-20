#include "object/AObject.hh"


AObject::AObject(AObjModule const &mod, int type) :
  AObjModule(mod)
{
  _type = type;

  initDefaultValue();
}

AObject::~AObject()
{

}

void AObject::update()
{
  updateBase();
}

void AObject::render()
{
  renderBase();
}

void         AObject::updateBase()
{

}

void         AObject::renderBase()
{
  convertToLayer();
  _sprt.setPosition(_disp.x, _disp.y);
  (*_layers)[_layer]->draw(_sprt);
}

void         AObject::initDefaultValue()
{
  _stp = 0;

  _lastType = -1;
  _anim = false;
  _animPos = 0;
  _animSpeed = 60;

  _depth = 0;
  _collType = 0;
  _collType = 0;

  _color.r = 255;
  _color.g = 255;
  _color.b = 255;
  _color.a = 255;

  _img.x = 0;
  _img.y = 0;
  _img.w = 0;
  _img.h = 0;

  _imgCtr.x = 0;
  _imgCtr.y = 0;
  _imgCtr.w = 0;
  _imgCtr.h = 0;

  _pos.x = 0;
  _pos.y = 0;

  _rot.x = 0;
  _rot.y = 0;
  _rot.w = 0;
  _rot.h = 0;

  _scl = 1;

  _disp.x = 0;
  _disp.y = 0;
  _disp.w = 0;

  _solid.x = 0;
  _solid.y = 0;
  _solid.w = 0;
  _solid.h = 0;
}

void         AObject::convertToIsometric()
{
  int        posX;
  int        posY;


  if (_cord->get("angle.x") == 0)
  {
    posX = _pos.x;
    posY = _pos.y;

  }
  if (_cord->get("angle.x") == 1)
  {
    posX = (TILE * _cord->get("map.w")) - _pos.y;
    posY = _pos.x;

  }
  if (_cord->get("angle.x") == 2)
  {
    posX = (TILE * _cord->get("map.w")) - _pos.x;
    posY = (TILE * _cord->get("map.w")) - _pos.y;

  }
  if (_cord->get("angle.x") == 3)
  {
    posX = _pos.y;
    posY = (TILE * _cord->get("map.w")) - _pos.x;
  }
  _iso.x = (TILE * _cord->get("map.w")) / 2;
  _iso.x -= posY / 2;
  _iso.x += posX / 2;

  _iso.x -= _imgCtr.x;

  _iso.y = posY / 4;
  _iso.y += posX / 4;
  _depth = _iso.y + (_pos.w / 2);
  _iso.y -= _imgCtr.y;
  _iso.y -= _pos.w / 2;
}

void         AObject::convertToLayer()
{
  _disp.x = _iso.x;
  _disp.y = _iso.y;

  _disp.x += _cord->get("camView.w") / 2;
  _disp.y += _cord->get("camView.h") / 2;

  _disp.x -= (_cord->get("tile.w") * _cord->get("map.w")) / 2;
  _disp.y -= (_cord->get("tile.h") * _cord->get("map.h")) / 2;
}

bool         AObject::convertToDisplay()
{
  _disp.x -= _cord->get("camera.x");
  _disp.y -= _cord->get("camera.y");
  if ((_disp.x > 0 - _img.w && _disp.x < _cord->get("win.w") + _img.w) &&
      (_disp.y > 0 - _img.h && _disp.y < _cord->get("win.w") + _img.h))
    return (true);
  return (false);
}

sf::Sprite const &AObject::getSprite() const
{
  return (_sprt);
}

CordRect   const &AObject::getPos() const
{
  return (_pos);
}

CordRect    const &AObject::getRot() const
{
  return (_rot);
}

float AObject::getScale() const
{
  return (_scl);
}

CordRect    const &AObject::getSolid() const
{
  return (_solid);
}

int          AObject::getCollType() const
{
  return (_collType);
}


void         AObject::setType(int) const
{

}

bool         AObject::getAnim() const
{
  return (_anim);
}

int          AObject::getAnimPos() const
{
  return (_animPos);
}

int          AObject::getAnimSpeed() const
{
  return (_animSpeed);
}

int          AObject::getType() const
{
  return (_type);
}

int          AObject::getDepth() const
{
  return (_depth);
}

int          AObject::getLayer() const
{
  return (_layer);
}

void         AObject::setPos(int x, int y)
{
  _pos.x = x;
  _pos.y = y;
  _pos.w = 0;
}

void         AObject::setPos(int x, int y, int z)
{
  _pos.x = x;
  _pos.y = y;
  _pos.w = z;
}

void         AObject::setRot(int rot, int x, int y)
{
  _rot.x = rot;
  _rot.w = (x == 0 ? 0 : 1);
  _rot.h = (y == 0 ? 0 : 1);
}

void         AObject::setScale(float scl)
{
  _scl = scl;
}

void         AObject::setSolid(CordRect const &cage)
{
  _solid = cage;
}

void         AObject::setAnim(bool anim)
{
  _anim = anim;
}

void         AObject::setAnimPos(int pos)
{
  _animPos = pos;
}

void         AObject::setAnimSpeed(int speed)
{
  _animSpeed = speed;
}
