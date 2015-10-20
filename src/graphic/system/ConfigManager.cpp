#include "system/ConfigManager.hh"

ConfigManager::ConfigManager() :
  AFileVarsManager()
{
  _path = "save/config";
  _defPath = "res/configs/config";
}

ConfigManager::~ConfigManager()
{
}
