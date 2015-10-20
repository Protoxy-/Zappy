#ifndef GAMECORE_HH_
# define GAMECORE_HH_

# include "System.hh"
# include "system/RessourceManager.hh"
# include "system/ConfigManager.hh"
# include "system/CordManager.hh"
# include "core/InputManager.hh"
# include "core/Client.hh"


class GameCore
{
protected:
  ConfigManager                             *_config;
  CordManager                               *_cord;

  sf::RenderWindow                          *_win;
  sf::Clock                                 *_clock;

  RessourceManager                          *_res;
  InputManager                              *_input;

  std::vector<std::string>                  *_teamNames;
  std::list<std::string>                    *_broadcast;

  std::string                               *_end;

public:
  GameCore();
  GameCore(GameCore const &);
  ~GameCore();

  void    initContext();

  ConfigManager      *getConfig() const;
  CordManager        *getCord() const;

  sf::RenderWindow   *getWin() const;

  RessourceManager   *getRes() const;
  InputManager       *getInput() const;
};

#endif // !GAMECORE_HH_
