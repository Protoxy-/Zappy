#include "core/Interpreter.hh"

Interpreter::Interpreter(GraphicCore const &core, MapManager *map) :
  GraphicCore(core)
{
  _eggId = -1;
  _map = map;
  _command.insert(std::make_pair("msz", &Interpreter::mapSize));
  _command.insert(std::make_pair("bct", &Interpreter::contentCase));
  _command.insert(std::make_pair("tna", &Interpreter::teamName));
  _command.insert(std::make_pair("pnw", &Interpreter::newPlayer));
  _command.insert(std::make_pair("ppo", &Interpreter::playerPosition));
  _command.insert(std::make_pair("plv", &Interpreter::playerLevel));
  _command.insert(std::make_pair("pin", &Interpreter::playerInventory));
  _command.insert(std::make_pair("pex", &Interpreter::playerExpulse));
  _command.insert(std::make_pair("pbc", &Interpreter::playerBroadcast));
  _command.insert(std::make_pair("pic", &Interpreter::firstIncantation));
  _command.insert(std::make_pair("pie", &Interpreter::endIncantation));
  _command.insert(std::make_pair("pfk", &Interpreter::playerEgg));
  _command.insert(std::make_pair("pdr", &Interpreter::playerThrow));
  _command.insert(std::make_pair("pgt", &Interpreter::playerTake));
  _command.insert(std::make_pair("pdi", &Interpreter::playerDead));
  _command.insert(std::make_pair("enw", &Interpreter::newEgg));
  _command.insert(std::make_pair("eht", &Interpreter::eggBirth));
  _command.insert(std::make_pair("ebo", &Interpreter::eggConnect));
  _command.insert(std::make_pair("edi", &Interpreter::eggDead));
  _command.insert(std::make_pair("sgt", &Interpreter::getTimeUnit));
  _command.insert(std::make_pair("sst", &Interpreter::setTimeUnit));
  _command.insert(std::make_pair("seg", &Interpreter::endGame));
  _command.insert(std::make_pair("smg", &Interpreter::message));
  _command.insert(std::make_pair("suc", &Interpreter::unknow));
  _command.insert(std::make_pair("sbp", &Interpreter::inputError));
}

Interpreter::~Interpreter()
{

}

void  Interpreter::update(std::vector<std::string> const &list)
{
  std::string   arg;
  size_t   i;
  size_t   j;

  for (i = 0; i < list.size(); i++)
  {
    _line = list[i];
    if (_command.find(_line.substr(0, 3)) != _command.end())
    {
      if (!_arg.empty())
        _arg.erase(_arg.begin(), _arg.end());
      arg = "";
      for (j = 0; j < _line.size(); j++)
      {
        if (_line[j] == '#')
          j++;
        if (_line[j] != ' ')
          arg += _line[j];
        if (_line[j] == ' ' || j + 1 == _line.size())
        {
          _arg.push_back(arg);
          arg = "";
        }
      }
      (this->*(*_command.find(_line.substr(0, 3))).second)();
    }
  }


}

void    Interpreter::mapSize()
{
  _cord->set("map.w", atoi(_arg[1].c_str()));
  _cord->set("map.h", atoi(_arg[2].c_str()));
}

void    Interpreter::contentCase()
{
  int   type;
  int   i;
  int   n;

  int   x = atoi(_arg[1].c_str());
  int   y = atoi(_arg[2].c_str());
  for (type = 3; type < 10; type++)
  {
    n = atoi(_arg[type].c_str());
    n -= _map->getItemNb(type - 3, x, y);
    if (n < 0)
    {
      for (i = n; i < 0; i++)
        _map->delItem(type - 3, x, y);
    }
    if (n > 0)
    {
      for (i = 0; i < n; i++)
        _map->addItem(type - 3, x, y);
    }
  }

}

void    Interpreter::teamName()
{
  _teamNames->push_back(_arg[1]);
}

void    Interpreter::newPlayer()
{
  ObjPlayer *player;


    if (_map->getPlayer(atoi(_arg[1].c_str())) == NULL)
    {

      player = new ObjPlayer(*this, 0, atoi(_arg[2].c_str()), atoi(_arg[3].c_str()), 0);
      player->setId(atoi(_arg[1].c_str()));
      player->setDir(atoi(_arg[4].c_str()));
      player->setLevel(atoi(_arg[5].c_str()) - 1);
      player->setTeamName(_arg[6]);
      _map->addPlayer(player);
    }
}

void    Interpreter::playerPosition()
{
  AObjPlayer *player;

  player = _map->getPlayer(atoi(_arg[1].c_str()));
  player->setMove(atoi(_arg[2].c_str()), atoi(_arg[3].c_str()), atoi(_arg[4].c_str()));
}

void    Interpreter::playerLevel()
{
  AObjPlayer *player;

  player = _map->getPlayer(atoi(_arg[1].c_str()));
  player->setLevel(atoi(_arg[2].c_str()) - 1);
}

void    Interpreter::playerInventory()
{
  AObjPlayer *player;
  int         i;

  player = _map->getPlayer(atoi(_arg[1].c_str()));
  for (i = 0; i < 7; i++)
  {
    player->setInventory(i, atoi(_arg[4 + i].c_str()));
  }
}

void    Interpreter::playerExpulse()
{

}

void    Interpreter::playerBroadcast()
{
  _broadcast->push_front(_line.substr(3, _line.size()));
  if (_broadcast->size() > static_cast<size_t>(_config->get("broadcastList")))
    _broadcast->pop_back();
}

void    Interpreter::firstIncantation()
{

}

void    Interpreter::endIncantation()
{

}

void    Interpreter::playerEgg()
{

}

void    Interpreter::playerThrow()
{

}

void    Interpreter::playerTake()
{

}

void    Interpreter::playerDead()
{
  AObjPlayer *player;

  player = _map->getPlayer(atoi(_arg[1].c_str()));
  player->setDead();
  _map->delPlayer(atoi(_arg[1].c_str()));
}

void    Interpreter::newEgg()
{
  ObjEgg *egg;

  egg = new ObjEgg(*this, 0, atoi(_arg[3].c_str()), atoi(_arg[4].c_str()), 0);
  egg->setId(atoi(_arg[1].c_str()));
  egg->setTeamName(_map->getPlayer(atoi(_arg[2].c_str()))->getTeamName());
  _map->addPlayer(egg);
}

void    Interpreter::eggBirth()
{

}

void    Interpreter::eggConnect()
{
  _map->delPlayer(atoi(_arg[1].c_str()));
}

void    Interpreter::eggDead()
{
  AObjPlayer *player;

  player = _map->getPlayer(atoi(_arg[1].c_str()));
  player->setDead();
  _map->delPlayer(atoi(_arg[1].c_str()));
}

void    Interpreter::getTimeUnit()
{
  _cord->set("time", atoi(_arg[1].c_str()));
}

void    Interpreter::setTimeUnit()
{

}

void    Interpreter::endGame()
{
  *_end = _arg[1];
}

void    Interpreter::message()
{

}

void    Interpreter::unknow()
{

}

void    Interpreter::inputError()
{

}
