#ifndef GAMEENGINE_HH_
# define GAMEENGINE_HH_

# include "System.hh"
# include "core/GameCore.hh"
# include "engine/GraphicEngine.hh"
# include "core/Interpreter.hh"

class             GameEngine : public GameCore
{
  Client            *_client;
  Interpreter       *_interpreter;

  GraphicEngine     *_layout;

  int             _fps;
  int             _stp;

public:
  GameEngine();
  ~GameEngine();

  void  initialize(int ac, const char **av);
  void  exit();
  bool  loop();
  bool  update();
  void  display();
};

#endif // !GAMEENGINE_HH_
