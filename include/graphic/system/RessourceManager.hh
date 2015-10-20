//
// RessourceManager.hh for zappy
//
// Made by Francois Hoertel
// Login   <hoerte_f@epitech.eu>
//
// Started on  Wed May 27 09:43:50 2015 Francois Hoertel
// Last update Wed May 27 09:43:50 2015 Francois Hoertel
//

#ifndef RESSOURCEMANAGER_HH_
# define RESSOURCEMANAGER_HH_

# include "System.hh"

class RessourceManager
{
  std::map<std::string, sf::SoundBuffer*> _sounds;
  std::map<std::string, sf::Texture*> _textures;
  std::map<std::string, sf::Font*> _fonts;

private:
  static const std::string SOUNDS_PATH;
  static const std::string IMAGES_PATH;
  static const std::string FONTS_PATH;

public:
  RessourceManager();
  ~RessourceManager();
  sf::SoundBuffer const &loadSound(std::string const &name);
  sf::Texture     const &loadImage(std::string const &name);
  sf::Font        const &loadFont(std::string const &name);
};

#endif // !RESSOURCEMANAGER_HH_
