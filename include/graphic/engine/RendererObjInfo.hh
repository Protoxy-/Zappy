#ifndef RENDEREROBJINFO_HH_
# define RENDEREROBJINFO_HH_

# include "System.hh"
# include "engine/ARenderer.hh"
# include "core/MapManager.hh"

class             RendererObjInfo : public ARenderer
{
  MapManager      *_map;

  sf::Sprite      _sprtOverSel;
  sf::Sprite      _sprtOverAct;
  sf::Sprite      _sprtInterBack;
  sf::Sprite      _sprtInterButton;

  CordRect        _caseSel;


public:
  RendererObjInfo(GraphicCore const &, MapManager *);
  ~RendererObjInfo();


  void  update();

  void  updateObjSel();

  void  draw();

  void  drawInterface();
};

#endif // !RENDEREROBJINFO_HH_
