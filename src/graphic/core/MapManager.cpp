#include "core/MapManager.hh"

MapManager::MapManager(const AObjModule  &mod) :
  AObjModule(mod)
{
  _env = new std::list<AObjEnv*>;
  _effect = new std::list<AObjEffect*>;
  _item = new std::list<AObjItem*>;
  _player = new std::list<AObjPlayer*>;
}

MapManager::~MapManager()
{

}

void  MapManager::generateEnv()
{
  int   i;
  int   j;

  for (i = 0; i < _cord->get("map.w"); i++)
    for (j = 0; j < _cord->get("map.h"); j++)
      addEnv(new ObjFloor(*this, 0, i, j, -12));

  //  _map->addEnv(new ObjGround(*_objMod, 0, i % 10, i / 10, -60 - j * 48));
  _cord->set("map", 1);
}

std::list<AObjEnv*>  *MapManager::getEnv() const
{
  return _env;
}

std::list<AObjEffect*>  *MapManager::getEffect() const
{
  return _effect;
}

std::list<AObjItem*>  *MapManager::getItem() const
{
  return _item;
}

std::list<AObjPlayer*>  *MapManager::getPlayer() const
{
  return _player;
}

AObjPlayer             *MapManager::getPlayer(int id) const
{
  std::list<AObjPlayer*>::iterator  it;

  for (it = _player->begin(); it != _player->end(); it++)
  {
    if ((*it)->getId() == static_cast<size_t>(id))
      break;
  }
  if (it == _player->end())
    return (NULL);
  return (*it);
}

std::vector<int> const &MapManager::getPlayerIds(int x, int y) const
{
  std::vector<int>  *ids = new std::vector<int>;
  std::list<AObjPlayer*>::iterator  it;

  for (it = _player->begin(); it != _player->end(); it++)
  {
    if ((*it)->getPos().x / TILE == x && (*it)->getPos().y / TILE == y)
      ids->push_back((*it)->getId());
  }
  if (ids->empty())
    ids->push_back(-1);
  return *ids;
}

int                     MapManager::getPlayerNbTeam(std::string const &name) const
{
  std::list<AObjPlayer*>::iterator  it;
  int   nb;

  nb = 0;
  for (it = _player->begin(); it != _player->end(); it++)
  {
    if ((*it)->getTeamName() == name)
      nb++;
  }
  return nb;
}



void  MapManager::addEnv(AObjEnv *obj)
{
  _env->push_back(obj);
}

void  MapManager::addEffect(AObjEffect *obj)
{
  _effect->push_back(obj);
}

void  MapManager::addItem(AObjItem *obj)
{
  _item->push_back(obj);
}

void  MapManager::addItem(int kind, int x, int y)
{
  switch (kind)
  {
    case 0:
      _item->push_back(new ObjFood(*this, 0, x, y, 0));
      break;
    case 1:
      _item->push_back(new StoneLinemate(*this, 0, x, y, 0));
      break;
    case 2:
      _item->push_back(new StoneDeraumere(*this, 0, x, y, 0));
      break;
    case 3:
      _item->push_back(new StoneSibur(*this, 0, x, y, 0));
      break;
    case 4:
      _item->push_back(new StoneMendian(*this, 0, x, y, 0));
      break;
    case 5:
      _item->push_back(new StonePhiras(*this, 0, x, y, 0));
      break;
    case 6:
      _item->push_back(new StoneThystame(*this, 0, x, y, 0));
      break;
    default:
      break;
  }
}

void  MapManager::delItem(int kind, int x, int y)
{
  std::list<AObjItem*>::iterator  it;

  for (it = _item->begin(); it != _item->end(); it++)
  {
    if ((*it)->getType() == kind && (*it)->getOrigin().x == x && (*it)->getOrigin().y  == y)
      break;
  }
  if (it != _item->end())
  {
    _item->erase(it);
  }
}

int   MapManager::getItemNb(int kind, int x, int y) const
{
  std::list<AObjItem*>::iterator  it;
  int                             nb;

  nb = 0;
  for (it = _item->begin(); it != _item->end(); it++)
  {
    if ((*it)->getType() == kind && (*it)->getOrigin().x == x && (*it)->getOrigin().y  == y)
    {
      nb++;
    }
  }
  return (nb);
}

int   MapManager::getItemNbAll(int kind) const
{
  std::list<AObjItem*>::iterator  it;
  int                             nb;

  nb = 0;
  for (it = _item->begin(); it != _item->end(); it++)
  {
    if ((*it)->getType() == kind)
      nb++;
  }
  return (nb);
}


void  MapManager::addPlayer(AObjPlayer *obj)
{
  _player->push_back(obj);
}

void  MapManager::delPlayer(int id)
{
  std::list<AObjPlayer*>::iterator  it;

  for (it = _player->begin(); it != _player->end(); it++)
  {
    if ((*it)->getId() == static_cast<size_t>(id))
      break;
  }
  if (it != _player->end())
  {
    delete *it;
    _player->erase(it);
  }
}

void  MapManager::updateEnv()
{
  std::list<AObjEnv*>::iterator  it;

  for (it = _env->begin(); it != _env->end(); it++)
  {
    (*it)->update();
  }
}

void  MapManager::updateEffect()
{
  std::list<AObjEffect*>::iterator  it;


  for (it = _effect->begin(); it != _effect->end(); it++)
  {
    (*it)->update();
  }
}

void  MapManager::updateItem()
{
  std::list<AObjItem*>::iterator  it;


  for (it = _item->begin(); it != _item->end(); it++)
  {
    (*it)->update();
  }
}

void  MapManager::updatePlayer()
{
  std::list<AObjPlayer*>::iterator  it;


  for (it = _player->begin(); it != _player->end(); it++)
  {
    (*it)->update();
  }
}



void  MapManager::update()
{
  updateEnv();
  updateEffect();
  updateItem();
  updatePlayer();
}
