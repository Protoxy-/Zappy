#ifndef RENDEREROBJECT_HH_
# define RENDEREROBJECT_HH_

# include "System.hh"
# include "engine/ARenderer.hh"
# include "engine/RendererObjInfo.hh"
# include "core/MapManager.hh"

class             RendererObject : public ARenderer
{
  MapManager                          *_map;

  std::vector<std::list<AObjEnv*>*>          _objEnv;
  std::vector<std::list<AObjEffect*>*>       _objEffect;
  std::vector<std::list<AObjItem*>*>         _objItem;
  std::vector<std::list<AObjPlayer*>*>       _objPlayer;
  int                                        _depthDec;

public:
  RendererObject(GraphicCore const &, MapManager *);
  ~RendererObject();

  void  update();
  void  draw();

  void  reset();
  void  arrange();
  void  layout();
};

#endif // !RENDEREROBJECT_HH_
