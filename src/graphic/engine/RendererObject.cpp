#include "engine/RendererObject.hh"

RendererObject::RendererObject(GraphicCore const &core, MapManager *map) :
  ARenderer(core)
{
  int   i;
  int   s;

  _map = map;

  _depthDec = _cord->get("depth.x") * -1;
  s = _cord->get("depth.w");
  for (i = _cord->get("depth.x"); i < s; i++)
  {
    _objEnv.push_back(new std::list<AObjEnv*>);
    _objEffect.push_back(new std::list<AObjEffect*>);
    _objItem.push_back(new std::list<AObjItem*>);
    _objPlayer.push_back(new std::list<AObjPlayer*>);
  }
}

RendererObject::~RendererObject()
{

}


void  RendererObject::update()
{
}

void  RendererObject::reset()
{
    std::list<AObjEnv*>::iterator     itEv;
    std::list<AObjEnv*>               *objEv;
    std::list<AObjEffect*>::iterator  itEf;
    std::list<AObjEffect*>            *objEf;
    std::list<AObjItem*>::iterator    itIt;
    std::list<AObjItem*>              *objIt;
    std::list<AObjPlayer*>::iterator  itPl;
    std::list<AObjPlayer*>            *objPl;
    size_t   i;

    for (i = 0; i < _objEnv.size(); i++)
    {
      objEv = _objEnv[i];
      objEf = _objEffect[i];
      objIt = _objItem[i];
      objPl = _objPlayer[i];
      if (_cord->get("layer") == _cord->get("layer.w") - 1 && !objEv->empty())
      {
        _objEnv[i]->erase(_objEnv[i]->begin(), _objEnv[i]->end());
      }
      if (_cord->get("layer") == _cord->get("layer.w") + 2 && !objEf->empty())
      {
        _objEffect[i]->erase(_objEffect[i]->begin(), _objEffect[i]->end());
      }
      if (_cord->get("layer") == _cord->get("layer.w") && !objIt->empty())
      {
        _objItem[i]->erase(_objItem[i]->begin(), _objItem[i]->end());
      }
      if (_cord->get("layer") == _cord->get("layer.w") && !objPl->empty())
      {
        _objPlayer[i]->erase(_objPlayer[i]->begin(), _objPlayer[i]->end());
      }
    }
}

void  RendererObject::arrange()
{
  std::list<AObjEnv*>::iterator     itEv;
  std::list<AObjEffect*>::iterator  itEf;
  std::list<AObjItem*>::iterator    itIt;
  std::list<AObjPlayer*>::iterator  itPl;

  if (_cord->get("layer") == _cord->get("layer.w") - 1 && !_map->getEnv()->empty())
  for (itEv = _map->getEnv()->begin(); itEv != _map->getEnv()->end(); itEv++)
  {
    (*itEv)->convertToIsometric();
    _objEnv[(*itEv)->getDepth() + _depthDec]->push_back((*itEv));
  }
  if (_cord->get("layer") == _cord->get("layer.w") + 2 && !_map->getEffect()->empty())
  for (itEf = _map->getEffect()->begin(); itEf != _map->getEffect()->end(); itEf++)
  {
    (*itEf)->convertToIsometric();
    _objEffect[(*itEf)->getDepth() + _depthDec]->push_back((*itEf));
  }
  if (_cord->get("layer") == _cord->get("layer.w") && !_map->getItem()->empty())
  for (itIt = _map->getItem()->begin(); itIt != _map->getItem()->end(); itIt++)
  {
    (*itIt)->convertToIsometric();
    _objItem[(*itIt)->getDepth() + _depthDec]->push_back((*itIt));
  }
  if (_cord->get("layer") == _cord->get("layer.w") && !_map->getPlayer()->empty())
  for (itPl = _map->getPlayer()->begin(); itPl != _map->getPlayer()->end(); itPl++)
  {
    (*itPl)->convertToIsometric();
    _objPlayer[(*itPl)->getDepth() + _depthDec]->push_back((*itPl));
  }
}

void  RendererObject::layout()
{
  std::list<AObjEnv*>::iterator     itEv;
  std::list<AObjEnv*>               *objEv;
  std::list<AObjEffect*>::iterator  itEf;
  std::list<AObjEffect*>            *objEf;
  std::list<AObjItem*>::iterator    itIt;
  std::list<AObjItem*>              *objIt;
  std::list<AObjPlayer*>::iterator  itPl;
  std::list<AObjPlayer*>            *objPl;
  size_t   i;

  for (i = 0; i < _objEnv.size(); i++)
  {
    objEv = _objEnv[i];
    objEf = _objEffect[i];
    objIt = _objItem[i];
    objPl = _objPlayer[i];
    if (_cord->get("layer") == _cord->get("layer.w") - 1 && !objEv->empty())
      for (itEv = objEv->begin(); itEv != objEv->end(); itEv++)
        (*itEv)->render();
    if (_cord->get("layer") == _cord->get("layer.w") + 2 && !objEf->empty())
      for (itEf = objEf->begin(); itEf != objEf->end(); itEf++)
        (*itEf)->render();
    if (_cord->get("layer") == _cord->get("layer.w") && !objIt->empty())
      for (itIt = objIt->begin(); itIt != objIt->end(); itIt++)
        (*itIt)->render();
    if (_cord->get("layer") == _cord->get("layer.w") && !objPl->empty())
      for (itPl = objPl->begin(); itPl != objPl->end(); itPl++)
        (*itPl)->render();
  }
}

void  RendererObject::draw()
{
  reset();
  arrange();
  layout();
}
