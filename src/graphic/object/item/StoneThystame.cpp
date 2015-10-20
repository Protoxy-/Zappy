#include "object/item/StoneThystame.hh"

StoneThystame::StoneThystame(AObjModule const &core, int _type, int x, int y, int z) :
  AObjItemStone(core, (_type == 0 ? 6 : _type), x, y, z)
{
  _sprt.setTexture(_res->loadImage("stones/thystame.png"));
}

StoneThystame::~StoneThystame()
{

}

void    StoneThystame::update()
{
  updateItem();
}

void    StoneThystame::render()
{
  renderItem();
}
