#include "object/item/StonePhiras.hh"

StonePhiras::StonePhiras(AObjModule const &core, int _type, int x, int y, int z) :
  AObjItemStone(core, (_type == 0 ? 5 : _type), x, y, z)
{
  _sprt.setTexture(_res->loadImage("stones/phiras.png"));
}

StonePhiras::~StonePhiras()
{

}

void    StonePhiras::update()
{
  updateItem();
}

void    StonePhiras::render()
{
  renderItem();
}
