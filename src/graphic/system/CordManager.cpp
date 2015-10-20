#include "system/CordManager.hh"

CordManager::CordManager() :
  AFileVarsManager()
{
  _path = "save/cord";
  _defPath = "res/configs/cord";
}

CordManager::~CordManager()
{
}
