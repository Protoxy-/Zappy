#include "object/item/StoneSibur.hh"

StoneSibur::StoneSibur(AObjModule const &core, int _type, int x, int y, int z) :
  AObjItemStone(core, (_type == 0 ? 3 : _type), x, y, z)
{
  _sprt.setTexture(_res->loadImage("stones/sibur.png"));
}

StoneSibur::~StoneSibur()
{

}

void    StoneSibur::update()
{
  updateItem();

}

void    StoneSibur::render()
{

  renderItem();

}
