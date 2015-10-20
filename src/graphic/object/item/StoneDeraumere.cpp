#include "object/item/StoneDeraumere.hh"

StoneDeraumere::StoneDeraumere(AObjModule const &core, int _type, int x, int y, int z) :
  AObjItemStone(core, (_type == 0 ? 2 : _type), x, y, z)
{
  _sprt.setTexture(_res->loadImage("stones/deraumere.png"));
}

StoneDeraumere::~StoneDeraumere()
{

}

void    StoneDeraumere::update()
{
  updateItem();
}

void    StoneDeraumere::render()
{
  renderItem();
}
