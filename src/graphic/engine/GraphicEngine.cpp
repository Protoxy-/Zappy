#include "engine/GraphicEngine.hh"
#include "object/item/StoneLinemate.hh"

GraphicEngine::GraphicEngine(GameCore const &core) :
  GraphicCore(core)
{
  _objMod = new AObjModule(*this);
  _map = new MapManager(*_objMod);

  _renderObj = new RendererObject(*this, _map);
  _renderInter = new RendererInterface(*this, _map);
  _renderEnv = new RendererEnv(*this);
  _camera = new Camera(*this);
  _layerPos.w = _cord->get("layer.w");
  _layerPos.h = _cord->get("layer.h");
  loading();
  loadRessource();
  _stp = 0;
}

GraphicEngine::~GraphicEngine()
{
  delete _renderObj;
  delete _renderInter;
  delete _renderEnv;
}

void  GraphicEngine::loading()
{
  sf::Sprite back(_res->loadImage("interface/loadBack.jpg"));
  sf::Text   text;

  sf::Vector2<float>                   pos;

  text.setFont(_res->loadFont("Main.ttf"));
  text.setCharacterSize(100);
  text.setColor(sf::Color(128,255,255,192));
  text.setString("Loading...");

  back.scale(_cord->get("win.w") / 1920, _cord->get("win.h") / 1080);

  pos.x = _cord->get("win.w") / 2 - text.getLocalBounds().width / 2;
  pos.y = _cord->get("win.h") / 3;
  text.setPosition(pos);

  _win->clear();
  _win->draw(back);
  _win->draw(text);
  _win->display();
}

void  GraphicEngine::gameWin()
{
  sf::Sprite back(_res->loadImage("interface/loadBack.jpg"));
  sf::Text   text;

  sf::Vector2<float>                   pos;

  text.setFont(_res->loadFont("Main.ttf"));
  text.setCharacterSize(100);
  text.setColor(sf::Color(128,255,255,192));
  text.setString("The team " + *_end + " wins !");

  back.scale(_cord->get("win.w") / 1920, _cord->get("win.h") / 1080);

  pos.x = _cord->get("win.w") / 2 - text.getLocalBounds().width / 2;
  pos.y = _cord->get("win.h") / 3;
  text.setPosition(pos);

  _win->clear();
  _win->draw(back);
  _win->draw(text);

  _win->draw(text);
  _win->display();
  sleep(5);
}

MapManager *GraphicEngine::getMap() const
{
  return _map;
}

GraphicCore const &GraphicEngine::getCore()
{
  return *this;
}

void  GraphicEngine::initialize()
{

}

void  GraphicEngine::initLayers()
{
  sf::RenderTexture   *layer;
  int                  w;
  int                  h;
  int                  i;

  w = _cord->get("camView.w");
  h = _cord->get("camView.h");
  for (i = 0; i < _layerPos.h; i++)
  {
    layer = new sf::RenderTexture();
    layer->create(w, h);
    layer->clear(sf::Color(0, 0, 0, 0));
    _layers->push_back(layer);
    _layerRefresh->push_back(false);
  }
}


void    GraphicEngine::loadRessource()
{
  sf::Sound   music;

  music.setBuffer(_res->loadSound("Main.wav"));
  music.play();
  _res->loadImage("back/sky.jpg");
  _res->loadImage("env/floor/Grass0.png");
  _res->loadImage("env/floor/Grass1.png");
  _res->loadImage("env/floor/Grass2.png");
  _res->loadImage("env/block/Ground0.png");
  _res->loadImage("env/block/Ground1.png");
  _res->loadImage("character/Player.png");
  _res->loadImage("interface/Outback.png");
  _res->loadImage("interface/Outback.png");
  _res->loadImage("interface/Inback.png");
  _res->loadImage("interface/SelBar.png");
  _res->loadImage("item/foodIcon.png");
  _res->loadImage("stones/linemateIcon.png");
  _res->loadImage("stones/deraumereIcon.png");
  _res->loadImage("stones/siburIcon.png");
  _res->loadImage("stones/mendianeIcon.png");
  _res->loadImage("stones/phirasIcon.png");
  _res->loadImage("stones/thystameIcon.png");
}


void  GraphicEngine::exit()
{

}

bool  GraphicEngine::update()
{
  if (!_win->isOpen())
    return false;
  if (_cord->get("map") == 0 && _cord->get("map.w") != 0)
  {
    _camera->init();
    initLayers();
  }
  _camera->update();

  if (_cord->get("map") == 0 && _cord->get("map.w") != 0)
    _map->generateEnv();
  _map->update();
  _renderEnv->update();
  _renderObj->update();
  _renderInter->update();
  return true;
}

void  GraphicEngine::renderLayers()
{
  _renderObj->draw();
}

void  GraphicEngine::drawLayers()
{
  const sf::Texture    text;
  sf::Sprite     layer;
  sf::Rect<int>  view;
  float zoom;

  for (_layerPos.x = 0; _layerPos.x < _layerPos.h; _layerPos.x++)
  {
    (*_layers)[_layerPos.x]->display();
    if (_config->get("antialiasing") == 1)
      (*_layers)[_layerPos.x]->setSmooth(true);
    layer.setTexture((*_layers)[_layerPos.x]->getTexture());
    zoom = _cord->get("zoom.x");
    zoom /= 48;
    view.width = _cord->get("win.w") / zoom;
    view.height = _cord->get("win.h") / zoom;

    view.left = _cord->get("camera.x") - view.width / 2;
    view.top = _cord->get("camera.y") - view.height / 2;
    layer.setTextureRect(view);
    layer.setScale(zoom, zoom);
    _win->draw(layer);
  }
}

void  GraphicEngine::draw()
{
  (*_layerRefresh)[_cord->get("layer.w")] = false;
  (*_layerRefresh)[_cord->get("layer.w") - 1] = false;
  for (_layerPos.x = 0; _layerPos.x < _layerPos.h; _layerPos.x++)
  {
    if ((*_layerRefresh)[_layerPos.x] == false)
    {
      _cord->set("layer", _layerPos.x);
      (*_layers)[_layerPos.x]->clear(sf::Color(0, 0, 0, 0));
      renderLayers();
      (*_layerRefresh)[_layerPos.x] = true;
    }
  }
  _renderEnv->draw();
  drawLayers();
  _renderInter->draw();
  _stp++;
}
