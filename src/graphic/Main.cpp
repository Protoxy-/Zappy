#include "System.hh"
#include "core/GameEngine.hh"

int          main(int ac, const char **av)
{
  GameEngine game;
  int        ret;

  try
  {
    game.initialize(ac, av);
  }
  catch (std::exception &e)
  {
    std::cout << "Error on initialization:" << e.what() << std::endl;
    return -1;
  }
  ret = game.loop();
  ret *= -1;
  game.exit();
  return ret;
}
