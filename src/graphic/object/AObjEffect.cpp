#include "object/AObjEffect.hh"

AObjEffect::AObjEffect(AObjModule const &core, int type, int x, int y, int z) :
  AObject(core, type)
{
  _layer = _cord->get("layer.w");
  _pos.x = x;
  _pos.y = y;
  _pos.w = z;
}

AObjEffect::~AObjEffect()
{

}

void AObjEffect::update()
{

}

void AObjEffect::render()
{

}
