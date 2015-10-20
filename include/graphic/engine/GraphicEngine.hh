#ifndef GRAPHICENGINE_HH_
# define GRAPHICENGINE_HH_

# include "System.hh"
# include "core/GameCore.hh"
# include "engine/GraphicCore.hh"

# include "core/MapManager.hh"

# include "engine/ARenderer.hh"
# include "engine/RendererEnv.hh"
# include "engine/RendererInterface.hh"
# include "engine/RendererObject.hh"

# include "engine/Camera.hh"
# include "core/AObjModule.hh"
# include "object/ObjIncludes.hh"


class GraphicEngine : public GraphicCore
{
  MapManager                *_map;
  AObjModule                *_objMod;

  RendererEnv               *_renderEnv;
  RendererInterface         *_renderInter;
  RendererObject            *_renderObj;


  Camera                    *_camera;

  CordRect                  _layerPos;

  size_t                    _stp;

public:
  GraphicEngine(GameCore const &);
  ~GraphicEngine();

  void  loading();
  void  gameWin();

  MapManager *getMap() const;

  void  initialize();
  void  initLayers();
  void  loadRessource();

  void  exit();


  GraphicCore const &getCore();
  bool  update();
  void  draw();

  void  renderLayers();
  void  drawLayers();
};

#endif // !GRAPHICENGINE_HH_
