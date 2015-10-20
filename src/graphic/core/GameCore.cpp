#include "core/GameCore.hh"

GameCore::GameCore()
{

  _config = new ConfigManager;
  _config->load();
  _cord = new CordManager;
  _cord->load();
  _cord->set("win.w", _config->get("windowSize", 0));
  _cord->set("win.h", _config->get("windowSize", 1));
  _res = new RessourceManager();

  _teamNames = new std::vector<std::string>;
  _broadcast = new std::list<std::string>;
  _end = new std::string;
  *_end = "";
  initContext();
}

GameCore::GameCore(GameCore const &obj)
{
  _config = obj._config;
  _cord = obj._cord;

  _win = obj._win;
  _clock = obj._clock;

  _res = obj._res;
  _input = obj._input;

  _teamNames = obj._teamNames;
  _broadcast = obj._broadcast;

  _end = obj._end;
}

GameCore::~GameCore()
{

}

void    GameCore::initContext()
{
  sf::VideoMode vm(_config->get("windowSize", 0), _config->get("windowSize", 1), 32);
  unsigned int  mode;

  mode = 0;
  if (_config->get("windowMode", 0) == 1)
    mode |= sf::Style::Fullscreen;
  if (_config->get("windowMode", 1) == 1)
    mode |= sf::Style::Default;
  _win = new sf::RenderWindow(vm, "Zappy", mode);
  _input = new InputManager(_win);
  _clock = new sf::Clock;
  _cord->set("win.x", _config->get("windowSize.x"));
  _cord->set("win.y", _config->get("windowSize.y"));
}

RessourceManager   *GameCore::getRes() const
{
  return _res;
}

ConfigManager  *GameCore::getConfig() const
{
  return _config;
}

CordManager    *GameCore::getCord() const
{
  return _cord;
}

InputManager       *GameCore::getInput() const
{
  return _input;
}

sf::RenderWindow   *GameCore::getWin() const
{
  return _win;
}
