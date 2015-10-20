#include "object/player/Player.hh"

ObjPlayer::ObjPlayer(AObjModule const &core, int _type, int x, int y, int z) :
AObjPlayer(core, _type, x, y, z)
{
  sf::Rect<int>   pos;

  pos.left = 0;
  pos.top = 0;
  pos.width = 96;
  pos.height = 96;
  _sprt.setTexture(_res->loadImage("character/Player.png"));
  _sprt.setTextureRect(pos);
  _stp = 0;
  _actionStp = 0;
  _actionTime = (_cord->get("time") > 60 ? 2 : _config->get("fps") / _cord->get("time"));
  _angle = 0;
  anim();

  initCordValues();
}

ObjPlayer::~ObjPlayer()
{

}

void    ObjPlayer::initCordValues()
{
  _img.w = 96;
  _img.h = 96;
  _imgCtr.x = _img.w / 2;
  _imgCtr.y = 72;

  _solid.x = TILE;
  _solid.y = TILE;
  _solid.w = TILE;
  _solid.h = 8;
  convertToIsometric();
}

void    ObjPlayer::move()
{
  if (_actionStp == 0)
  {
    _movePos.w = (_movePos.x - _pos.x) / _actionTime;
    _movePos.h = (_movePos.y - _pos.y) / _actionTime;
  }
  _pos.x += _movePos.w;
  _pos.y += _movePos.h;
  if (_actionStp++ >= _actionTime || _movePos.w > TILE || _movePos.h > TILE)
  {
    _pos.x = _movePos.x;
    _pos.y = _movePos.y;
    _movePos.x = 0;
    _movePos.y = 0;
    _actionStp = 0;
    _animPos = 0;
  }
}

void    ObjPlayer::anim()
{
  sf::Rect<int>   pos;

  pos = _sprt.getTextureRect();
  if (_actionStp <= 1)
  {
    _angle = ((_dir - 1) + _cord->get("angle")) % 4;
    if (_angle == 0)
    {
      pos.top = 96;
      _sprt.setScale(-1, 1);

    }
    else if (_angle == 1)
    {
      pos.top = 0;
      _sprt.setScale(-1, 1);

    }
    else if (_angle == 2)
    {
      pos.top = 0;
      _sprt.setScale(1, 1);

    }
    else if (_angle == 3)
    {
      pos.top = 96;
      _sprt.setScale(1, 1);
    }
  }

  pos.left = ((_animPos) % 6) * 96;
  _sprt.setTextureRect(pos);
  _animPos++;
}

void    ObjPlayer::updateColor()
{
  _color.a = 255;
  if (static_cast<int>(_id) == _cord->get("selPlayer"))
    _color.a = 200;
  std::cout << _level << std::endl;
  switch (_level)
  {
    case 0:
      _color.r = 255;
      _color.b = 255;
      _color.g = 255;
      break;
    case 1:
      _color.r = 194;
      _color.g = 255;
      _color.b = 64;
      break;
    case 2:
      _color.r = 255;
      _color.g = 128;
      _color.b = 0;
      break;
    case 3:
      _color.r = 255;
      _color.g = 0;
      _color.b = 0;
      break;
    case 4:
      _color.r = 255;
      _color.g = 0;
      _color.b = 128;
      break;
    case 5:
      _color.r = 128;
      _color.g = 0;
      _color.b = 255;
      break;
    case 6:
      _color.r = 0;
      _color.g = 0;
      _color.b = 255;
      break;
    case 7:
      _color.r = 0;
      _color.g = 128;
      _color.b = 255;
      break;
    default:
      break;
  }
  _sprt.setColor(_color);
}

void    ObjPlayer::update()
{
  updateBase();
  if (_movePos.x != 0)
  {
    move();
    anim();
  }
  updateColor();
  _stp++;
}

void    ObjPlayer::render()
{

  convertToLayer();
  if (static_cast<int>(_id) == _cord->get("selPlayer"))
  {
    _cord->set("selPlayer.w", _disp.x);
    _cord->set("selPlayer.h", _disp.y);
  }
  _sprt.setPosition(_disp.x + (_angle == 0 || _angle == 1 ? 96 : 0), _disp.y);
  (*_layers)[_layer]->draw(_sprt);
}
