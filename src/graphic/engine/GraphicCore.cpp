#include "engine/GraphicCore.hh"

GraphicCore::GraphicCore(GameCore const &core) :
  GameCore(core)
{
  _layers = new std::vector<sf::RenderTexture *>;
  _layerRefresh = new std::vector<bool>;

}



GraphicCore::GraphicCore(GraphicCore const &obj) :
  GameCore(obj)
{
  _layers = obj._layers;
  _layerRefresh = obj._layerRefresh;
}

GraphicCore::~GraphicCore()
{
}

std::vector<sf::RenderTexture *> *GraphicCore::getLayers() const
{
  return _layers;
}

std::vector<bool> *GraphicCore::getLayerRefresh() const
{
  return _layerRefresh;
}
