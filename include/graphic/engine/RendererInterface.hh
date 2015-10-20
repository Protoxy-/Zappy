#ifndef RENDERERINTERFACE_HH_
# define RENDERERINTERFACE_HH_

# include "System.hh"
# include "engine/ARenderer.hh"
# include "core/MapManager.hh"

class             ListCont
{
public:
  sf::Sprite                _sprt;
  std::string               _name;
  int                       _val;

  ListCont(sf::Sprite const &, std::string const &, int);
  ~ListCont();


};

class             RendererInterface : public ARenderer
{
  MapManager               *_map;

  sf::Sprite                _outbackL;
  sf::Sprite                _outbackR;
  sf::Sprite                _inback;
  sf::Sprite                _broadSprt;
  sf::Sprite                _selBar;

  sf::Text                  _categoryText;

  std::vector<std::string>  _categoryName;
  std::vector<std::string>  _itemName;
  std::vector<sf::Sprite*>  _itemSprt;
  std::vector<sf::Sprite*>  _teamSprt;

  std::list<ListCont*>      _listStat;
  std::list<ListCont*>      _listTeam;
  std::list<ListCont*>      _listItem;
  std::list<ListCont*>      _listBroad;
  std::list<ListCont*>      _listCase;
  std::list<ListCont*>      _listPlayer;

  CordRect                  _layout;

  CordRect                  _menu;

  bool                      _refresh;

public:
  RendererInterface(GraphicCore const &, MapManager *);
  ~RendererInterface();


  void  update();

  void  updateControl();

  void  updateStatList();
  void  updateItemList();
  void  updateTeamList();
  void  updateBroadList();
  void  updateCaseList();
  void  updatePlayerList();

  void  draw();

  void  drawList(std::list<ListCont*> const &);
  void  drawBackground();
  void  drawContent();
  void  drawMenu();

  void  drawStatList();
  void  drawItemList();
  void  drawTeamList();
  void  drawBroadList();
  void  drawCaseList();
  void  drawPlayerList();
};

#endif // !RENDERERINTERFACE_HH_
