#include "core/InputManager.hh"

InputManager::InputManager(sf::RenderWindow *win)
{
  _event = new sf::Event;
  _mouse = new sf::Mouse;
  _mousePosition = _mouse->getPosition();
  _win = win;
  _defKey = sf::Keyboard::Unknown;
}

InputManager::~InputManager()
{

}

bool  InputManager::update()
{

  while (_win->pollEvent(*_event))
  {

    // Close window : exit
  }
  _mousePosition = _mouse->getPosition();
  return true;
}

sf::Event  const &InputManager::getEvent() const
{
  return *_event;
}

sf::Keyboard::Key  const &InputManager::getKey() const
{
  if (_event->type == sf::Event::KeyPressed)
  return _defKey;
    return _event->key.code;
}

sf::Mouse  const &InputManager::getMouse() const
{
  return *_mouse;
}

sf::Vector2<int>  const &InputManager::getMousePos() const
{
  return _mousePosition;
}
