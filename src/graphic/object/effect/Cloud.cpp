#include "object/effect/Cloud.hh"

ObjCloud::ObjCloud(AObjModule const &core, int _type, int x, int y, int z) :
  AObjEffect(core, _type, x, y, z)
{
  _res->loadImage("effect/CloudG0.png");
  initCordValues();
}

ObjCloud::~ObjCloud()
{

}

void    ObjCloud::initCordValues()
{
  sf::Rect<int>   type;


  _layer = 4;
/*
  type.width = 250;
  type.height = 250;
  type.left = 250 * (_type % 4);
  type.top = 250 * (_type / 4);
  _sprt.setTextureRect(type);

*/
  _img.w = 250;
  _img.h = 250;
  _imgCtr.x = _img.w / 2;
  _imgCtr.y = _img.h / 2;

}

void    ObjCloud::update()
{

  updateBase();


}

void    ObjCloud::render()
{
  _sprt.setPosition(_pos.x, _pos.y);
  (*_layers)[_layer]->draw(_sprt);
  std::cout << "Cloud " << _pos.x << " " << _pos.y  << " " << _layer << std::endl;
}
