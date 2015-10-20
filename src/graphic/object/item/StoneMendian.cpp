#include "object/item/StoneMendian.hh"

StoneMendian::StoneMendian(AObjModule const &core, int _type, int x, int y, int z) :
  AObjItemStone(core, (_type == 0 ? 4 : _type), x, y, z)
{
  _sprt.setTexture(_res->loadImage("stones/mendiane.png"));
}

StoneMendian::~StoneMendian()
{

}

void    StoneMendian::update()
{
  updateItem();
}

void    StoneMendian::render()
{
  renderItem();
}
