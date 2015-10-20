#ifndef GRAPHICCORE_HH_
# define GRAPHICCORE_HH_

# include "System.hh"
# include "core/GameCore.hh"
# include "engine/GraphicCore.hh"

class GraphicCore : public GameCore
{
protected:
  std::vector<sf::RenderTexture *>          *_layers;
  std::vector<bool>                         *_layerRefresh;
  //Refresh 0: all BackLayers
  //Refresh i > 0: layer i

public:
  GraphicCore(GameCore const &);
  GraphicCore(GraphicCore const &);
  ~GraphicCore();

  std::vector<sf::RenderTexture *> *getLayers() const;
  std::vector<bool> *getLayerRefresh() const;
};

#endif // !GRAPHICCORE_HH_
