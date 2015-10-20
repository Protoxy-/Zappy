#ifndef INPUTMANAGER_HH_
# define INPUTMANAGER_HH_

# include "System.hh"

class InputManager
{
  sf::RenderWindow *_win;
  sf::Event        *_event;
  sf::Mouse        *_mouse;
  sf::Vector2<int> _mousePosition;
  sf::Keyboard::Key _defKey;

public:
  InputManager(sf::RenderWindow *);
  ~InputManager();

  bool  update();

  sf::Event  const &getEvent() const;
  sf::Keyboard::Key  const &getKey() const;
  sf::Mouse  const &getMouse() const;
  sf::Vector2<int>  const &getMousePos() const;
};

#endif // !INPUTMANAGER_HH_
