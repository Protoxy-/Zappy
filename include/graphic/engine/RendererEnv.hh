#ifndef RENDERERENV_HH_
# define RENDERERENV_HH_

# include "System.hh"
# include "engine/ARenderer.hh"
# include "object/effect/Cloud.hh"

class             RendererEnv : public ARenderer
{
  sf::Sprite      _back;
  sf::Sprite      _backEff;

  std::list<ObjCloud *>   _clouds;

public:
  RendererEnv(GraphicCore const &);
  ~RendererEnv();

  void  update();
  void  draw();

  void  drawBackground();
  void  drawClouds();
};

#endif // !RENDERERENV_HH_
