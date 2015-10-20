#ifndef AOBJMODULE_HH_
# define AOBJMODULE_HH_

# include "System.hh"
# include "system/RessourceManager.hh"
# include "system/ConfigManager.hh"
# include "system/CordManager.hh"
# include "engine/GraphicCore.hh"

class                                        AObjModule
{
protected:
  InputManager                              *_input;
  ConfigManager                             *_config;
  CordManager                               *_cord;

  sf::RenderWindow                          *_win;
  RessourceManager                          *_res;

  std::vector<sf::RenderTexture *>          *_layers;

public:
  AObjModule(GraphicCore const &);
  AObjModule(AObjModule const &);
  ~AObjModule();
};

#endif // !AOBJMODULE_HH_
