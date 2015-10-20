#include "object/item/StoneLinemate.hh"

StoneLinemate::StoneLinemate(AObjModule const &core, int _type, int x, int y, int z) :
  AObjItemStone(core, (_type == 0 ? 1 : _type), x, y, z)
{
  _sprt.setTexture(_res->loadImage("stones/linemate.png"));
}

StoneLinemate::~StoneLinemate()
{

}

void    StoneLinemate::update()
{
  updateItem();
}

void    StoneLinemate::render()
{

  renderItem();

}
