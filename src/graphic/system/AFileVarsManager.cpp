#include "system/AFileVarsManager.hh"

AFileVarsManager::AFileVarsManager()
{
  _change = 0;
}

AFileVarsManager::~AFileVarsManager()
{
}

int     AFileVarsManager::getChange() const
{
  return _change;
}

void   AFileVarsManager::setChange(int change)
{
  _change = change;
}

void		AFileVarsManager::load(std::string const &path)
{
  if (path == "init")
    _vars = loadVarsFile(_defPath);
  else
    _vars = loadVarsFile(path);
}

void		AFileVarsManager::load()
{
  try
  {
    _vars = loadVarsFile(_path);
  }
  catch (errFile &e)
  {
    _vars = loadVarsFile(_defPath);
  }
}

void		AFileVarsManager::save()
{
  saveVarsFile(_path, _vars);
}

void    AFileVarsManager::reset()
{
  _vars = loadVarsFile(_defPath);
  _change = 1;
}

int  AFileVarsManager::checkPos(std::string const &name)
{
  char          chk;
  int           pos;

  if (name.substr(name.size() - 2)[0] != '.')
  {
    return -1;
  }
  chk = name.substr(name.size() - 1)[0];
  pos = -1;
  switch (chk)
  {
    case 'x':
      pos = 0;
      break;
    case 'y':
      pos = 1;
      break;
    case 's':
      pos = 1;
      break;
    case 'z':
      pos = 2;
      break;
    case 'w':
      pos = 2;
      break;
    case 'h':
      pos = 3;
      break;
    default:
      pos = -1;
      break;
  }
  return pos;
}


void  AFileVarsManager::set(std::string const &name, int pos, int val)
{

  if (_vars.find(name) == _vars.end())
    throw errLogical("No var called \"" + name + "\" in file \"" + _path);
  (*_vars.find(name)->second)[pos] = val;
  _change = 1;
}

void  AFileVarsManager::set(std::string const &name, int val)
{
  std::string   _name;
  int  pos;

  _name = name;
  pos = checkPos(name);
  if (pos != -1)
  {
    _name = name.substr(0, name.size() - 2);
  }
  else
    pos = 0;
  if (_vars.find(_name) == _vars.end())
    throw errLogical("No var called \"" + _name + "\" in file \"" + _path);
  (*_vars.find(_name)->second)[pos] = val;
  _change = 1;
}

void  AFileVarsManager::set(std::string const &name, CordRect const &vec)
{
  if (_vars.find(name) == _vars.end())
    throw errLogical("No var called \"" + name + "\" in file \"" + _path);
    (*_vars.find(name)->second)[0] = vec.x;
    (*_vars.find(name)->second)[1] = vec.y;
    (*_vars.find(name)->second)[2] = vec.w;
    (*_vars.find(name)->second)[3] = vec.h;
}

int         AFileVarsManager::get(std::string const &name, int pos) const
{
  if (_vars.find(name) == _vars.end())
    throw errLogical("No var called \"" + name + "\" in file \"" + _path);
  return ((*_vars.find(name)->second)[pos]);
}

int         AFileVarsManager::get(std::string const &name)
{
  std::string   _name;
  int  pos;

  _name = name;
  pos = checkPos(name);
  if (pos != -1)
    _name = name.substr(0, name.size() - 2);
  else
    pos = 0;

  if (_vars.find(_name) == _vars.end())
    throw errLogical("No var called \"" + _name + "\" in file \"" + _path);
  return ((*_vars.find(_name)->second)[pos]);
}
