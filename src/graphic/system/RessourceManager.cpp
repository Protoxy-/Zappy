#include "system/RessourceManager.hh"
#include "system/Exception.hh"

const std::string RessourceManager::IMAGES_PATH =
  "res/graphics/";
const std::string RessourceManager::FONTS_PATH =
  "res/fonts/";
const std::string RessourceManager::SOUNDS_PATH =
  "res/sounds/";

RessourceManager::RessourceManager()
{
}

RessourceManager::~RessourceManager()
{
  for (std::map<std::string, sf::Texture*>::const_iterator it = _textures.begin();
    it != _textures.end();) {
    delete it->second;
    _textures.erase(it++);
  }
}

sf::SoundBuffer const &RessourceManager::loadSound(std::string const &name)
{
  std::map<std::string, sf::SoundBuffer*>::const_iterator search;

  search = _sounds.find(name);
  if (search != _sounds.end())
    return *search->second;

  sf::SoundBuffer* buffer = new sf::SoundBuffer;
  std::string fullName = SOUNDS_PATH + name;
  if (!buffer->loadFromFile(fullName.c_str()))
    throw errFile("Failed to load: " + fullName);
  _sounds.insert(std::make_pair(name, buffer));
  return *buffer;
}

sf::Texture const &RessourceManager::loadImage(std::string const &name)
{
  std::map<std::string, sf::Texture*>::const_iterator search;

  search = _textures.find(name);
  if (search != _textures.end())
    return *search->second;

  sf::Texture* texture = new sf::Texture;
  std::string fullName = IMAGES_PATH + name;

  texture->loadFromFile(fullName.c_str());
  if (texture == NULL)
    throw errFile("Failed to load: " + fullName);
  _textures.insert(std::make_pair(name, texture));
  return *texture;
}

sf::Font const &RessourceManager::loadFont(std::string const &name)
{
  std::map<std::string, sf::Font*>::const_iterator search;

  search = _fonts.find(name);
  if (search != _fonts.end())
    return *search->second;

  sf::Font* font = new sf::Font;
  std::string fullName = FONTS_PATH + name;

  font->loadFromFile(fullName.c_str());
  if (font == NULL)
    throw errFile("Failed to load: " + fullName);
  _fonts.insert(std::make_pair(name, font));
  return *font;
}
