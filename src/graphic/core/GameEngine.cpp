#include "core/GameEngine.hh"

GameEngine::GameEngine() :
  GameCore()
{
  _client = new Client;
  _layout = new GraphicEngine(*this);
  _interpreter = new Interpreter(*_layout, _layout->getMap());

  _fps = _config->get("fps");
  _stp = 0;
}

GameEngine::~GameEngine()
{

}

void  GameEngine::initialize(int ac, const char **av)
{
  if (_client->initialize(ac, av) == false)
    throw errAbort("Connection");
  _layout->initialize();

}

void  GameEngine::exit()
{
  _layout->exit();
  delete _input;
  _win->close();
}

bool  GameEngine::loop()
{
  int   waitTime;

  while (42)
  {
    try
    {
      if (update() == false)
        return true;
      display();

      if (_clock->getElapsedTime().asMicroseconds() > 1000000 / _fps)
        waitTime = 1;
      else
        waitTime = (1000000 / _fps - _clock->getElapsedTime().asMicroseconds());
      usleep(waitTime);
    }
    catch (std::exception &e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      return false;
    }
  }
  return true;
}

bool  GameEngine::update()
{
  _clock->restart();
  _input->update();

  if (_input->getEvent().type == sf::Event::Closed || _input->getEvent().key.code == sf::Keyboard::Escape)
    return false;
  if (_end->size() != 0)
  {
    _layout->gameWin();
    return false;
  }
  if (_stp == _config->get("introTime"))
  {
    _config->set("introTime", 0);
  }

  _client->update();
  if (_client->getInput().size() != 0)
  {
    _interpreter->update(_client->getCommand());
  }
  if (_stp > 2)
    if (_layout->update() == false)
      return false;
  return true;
}

void  GameEngine::display()
{
  if (_stp > 2)
  {
    _win->clear();
    _layout->draw();
    _win->display();
  }
  _stp++;
}
