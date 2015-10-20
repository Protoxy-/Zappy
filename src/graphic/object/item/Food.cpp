#include "object/item/Food.hh"

ObjFood::ObjFood(AObjModule const &core, int _type, int x, int y, int z) :
  AObjItem(core, (_type == 0 ? 0 : _type), x, y, z)
{
  sf::Rect<int>   pos;

  pos.left = 0;
  pos.top = 32 * (rand() % 4);
  pos.width = 32;
  pos.height = 32;
  _sprt.setTexture(_res->loadImage("item/food.png"));
  _sprt.setTextureRect(pos);

  _img.w = 32;
  _img.h = 32;
  _imgCtr.x = _img.w / 2;
  _imgCtr.y = _img.h / 2 + 8;

  _solid.x = TILE;
  _solid.y = TILE;
  _solid.w = TILE;
  _solid.h = 8;
}

ObjFood::~ObjFood()
{

}

void    ObjFood::update()
{
  static int   rd = 2;
  CordRect        vec;
  CordRect        cord;
  sf::Rect<int>   rect;
  int             dir;



  if (_stp % rd == 0)
  {
    vec.x += (rand() % 30) - 15;
    vec.y += (rand() % 30) - 15;

    if (_pos.x + vec.x >= _origin.x * TILE - TILE / 2 && _pos.x + vec.x < _origin.x * TILE + TILE / 2)
    if (_pos.y + vec.y >= _origin.y * TILE - TILE / 2 && _pos.y + vec.y < _origin.y * TILE + TILE / 2)
    {
      cord.x = (vec.x < 0 ? vec.x * -1 : vec.x);
      cord.y = (vec.x < 0 ? vec.x * -1 : vec.y);
      if (cord.x > cord.y)
        dir = (vec.x < 0 ? 1 : 2);
      else
        dir = (vec.y < 0 ? 3 : 0);

      rect = _sprt.getTextureRect();
      rect.left = 32 * (_stp % 3);
      rect.top = 32 * dir;
      _sprt.setTextureRect(rect);

      _pos.x += vec.x;
      _pos.y += vec.y;

      rd = rand() % _config->get("foodSpeed") + 1;
    }
  }
  updateItem();
}

void    ObjFood::render()
{

  renderItem();
}
