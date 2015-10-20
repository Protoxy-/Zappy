#include "object/AObjItem.hh"

AObjItem::AObjItem(AObjModule const &core, int type, int x, int y, int z) :
AObject(core, type)
{
  _sprtShadow.setTexture(_res->loadImage("effect/ItemShadow.png"));
  _layer = _cord->get("layer.w");
  _origin.x = x;
  _origin.y = y;
  _origin.w = z;
  _pos.x = x * TILE;
  _pos.y = y * TILE;
  _pos.w = z;

  _pos.x += (rand() % TILE) - TILE / 2;
  _pos.y += (rand() % TILE) - TILE / 2;
  _stp = 0;
  _introT = (_config->get("introTime") == 0 ? 0 : (rand() % (_config->get("introTime") - 50)) + 50);
}

AObjItem::~AObjItem()
{

}

void AObjItem::update()
{

}

void AObjItem::render()
{

}

void AObjItem::updateItem()
{

}

void  AObjItem::renderItem()
{
  sf::Color color(255,255,255,0);
  size_t  depth;
  float   scale;

  if (_stp < _introT)
  {
    convertToLayer();
    depth = _disp.y;
    depth -= (_introT - _stp) * 1000 / _introT;
    _sprt.setPosition(_disp.x, depth);

    scale = _stp;
    scale *= 0.7;
    scale /= _introT;
    _sprtShadow.setScale(scale, scale);
    _sprtShadow.setPosition(_disp.x - 24 * scale, _disp.y + 24 - 12 * scale);
    color.a = _stp * 192 / _introT;
    _sprtShadow.setColor(color);
    (*_layers)[_layer]->draw(_sprtShadow);
    (*_layers)[_layer]->draw(_sprt);
  }
  else
  {
    convertToLayer();
    _sprt.setPosition(_disp.x, _disp.y);

    (*_layers)[_layer]->draw(_sprt);
  }
  _stp++;
}

CordRect const &AObjItem::getOrigin() const
{
  return _origin;
}

void            AObjItem::setOrigin(CordRect const &ori)
{
  _origin = ori;
}
