#include "engine/RendererObjInfo.hh"

RendererObjInfo::RendererObjInfo(GraphicCore const &core, MapManager *map) :
  ARenderer(core)
{
  _map = map;

  _sprtOverSel.setTexture(_res->loadImage("effect/SimpleTile.png"));
  _sprtOverAct.setTexture(_res->loadImage("effect/SimpleTile.png"));
  //_sprtInterBack;
  //_sprtInterButton;
  _caseSel.x = -1;
  _caseSel.y = -1;
  _caseSel.w = -1;
  _caseSel.h = -1;
}

RendererObjInfo::~RendererObjInfo()
{

}
/*if (_cord->get("angle.x") == 0)
{
  posX = _pos.x;
  posY = _pos.y;

}
if (_cord->get("angle.x") == 1)
{
  posX = (TILE * _cord->get("map.w")) - _pos.y;
  posY = _pos.x;

}
if (_cord->get("angle.x") == 2)
{
  posX = (TILE * _cord->get("map.w")) - _pos.x;
  posY = (TILE * _cord->get("map.w")) - _pos.y;

}
if (_cord->get("angle.x") == 3)
{
  posX = _pos.y;
  posY = (TILE * _cord->get("map.w")) - _pos.x;
}*/


void  RendererObjInfo::update()
{
  sf::Vector2<float>    _iso;

  //iso.x = ;
  //iso.y = ;
  _sprtOverSel.setPosition(_iso);
}

void  RendererObjInfo::draw()
{
  (*_layers)[_cord->get("layer.h") - 1]->draw(_sprtOverSel);
}
