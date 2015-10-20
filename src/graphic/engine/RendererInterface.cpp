#include "engine/RendererInterface.hh"

ListCont::ListCont(sf::Sprite const &sprt, std::string const &name, int val)
{
  _sprt = sprt;
  _name = name;
  _val = val;
}

ListCont::~ListCont()
{

}


RendererInterface::RendererInterface(GraphicCore const &core, MapManager *map) :
  ARenderer(core)
{
  _map = map;
  _refresh = true;
  _categoryName.push_back("Statistique");
  _categoryName.push_back("Equipe");
  _categoryName.push_back("Objets");
  _categoryName.push_back("Broadcast");
  _categoryName.push_back("Contenue");
  _categoryName.push_back("Joueur");

  _outbackL.setTexture(_res->loadImage("interface/Outback.png"));
  _outbackR.setTexture(_res->loadImage("interface/Outback.png"));
  _inback.setTexture(_res->loadImage("interface/Inback.png"));
  _selBar.setTexture(_res->loadImage("interface/SelBar.png"));

  _outbackL.setColor(sf::Color(255, 255, 255, _config->get("interfaceTransparency") * 128 / 100 + 127));
  _outbackR.setColor(_outbackL.getColor());
  _inback.setColor(sf::Color(255, 255, 255, _config->get("interfaceTransparency") * 192 / 100 + 63));


  _broadSprt.setTexture(_res->loadImage("interface/broadcastIcon.png"));

  _itemSprt.push_back(new sf::Sprite(_res->loadImage("item/foodIcon.png")));
  _itemSprt.push_back(new sf::Sprite(_res->loadImage("stones/linemateIcon.png")));
  _itemSprt.push_back(new sf::Sprite(_res->loadImage("stones/deraumereIcon.png")));
  _itemSprt.push_back(new sf::Sprite(_res->loadImage("stones/siburIcon.png")));
  _itemSprt.push_back(new sf::Sprite(_res->loadImage("stones/mendianeIcon.png")));
  _itemSprt.push_back(new sf::Sprite(_res->loadImage("stones/phirasIcon.png")));
  _itemSprt.push_back(new sf::Sprite(_res->loadImage("stones/thystameIcon.png")));
  _itemName.push_back("Nourriture");
  _itemName.push_back("Linemate");
  _itemName.push_back("Deraumere");
  _itemName.push_back("Sibur");
  _itemName.push_back("Mendiane");
  _itemName.push_back("Phiras");
  _itemName.push_back("Thystame");

  _teamSprt.push_back(new sf::Sprite(_res->loadImage("team/1.png")));
  _menu.x = 0;
  _menu.y = 0;
  _menu.w = 6;
  _menu.h = 7;

  _layout.w = 580;
  _layout.h = 300;

  sf::Vector2<float>  pos;

  pos.x = _cord->get("win.w") / 2 - _layout.w / 2;
  pos.y = _cord->get("win.h") - 300;
  _outbackL.setPosition(pos);

  pos.x += 50;
  _inback.setPosition(pos);
  _layout.x = pos.x;
  _layout.y = pos.y;

  pos.x += 466 + 50;
  _outbackR.setScale(-1, 1);
  _outbackR.setPosition(pos);

  _categoryText.setFont(_res->loadFont("Main.ttf"));
  _categoryText.setCharacterSize(22);
  _categoryText.setColor(sf::Color::Cyan);
}

RendererInterface::~RendererInterface()
{

}


void  RendererInterface::update()
{
  updateControl();

  if (_menu.x == 0)
    updateStatList();
  else if (_menu.x == 1)
    updateTeamList();
  else if (_menu.x == 2)
    updateItemList();
  else if (_menu.x == 3)
    updateBroadList();
  else if (_menu.x == 4)
    updateCaseList();
  else if (_menu.x == 5)
    updatePlayerList();
}

void  RendererInterface::updateControl()
{
  int id;

  if (_input->getMouse().isButtonPressed(sf::Mouse::Button::Left))
  {
    _cord->set("selCase.x", _cord->get("select.x"));
    _cord->set("selCase.y", _cord->get("select.y"));
    _menu.x = 4;
    id = _map->getPlayerIds(_cord->get("select.x"), _cord->get("select.y"))[0];
    if (id != -1)
    {
      _cord->set("selPlayer", id);
      _menu.x = 5;
      _refresh = true;
    }
  }

  if (_input->getEvent().type == sf::Event::KeyPressed)
  {
    if (_input->getEvent().key.code == sf::Keyboard::Left && _menu.x > 0)
    {
      _menu.x--;
      _menu.y = 0;
    }
    if (_input->getEvent().key.code == sf::Keyboard::Right && _menu.x < _menu.w - 1)
    {
      _menu.x++;
      _menu.y = 0;
    }
    if (_input->getEvent().key.code == sf::Keyboard::Up && _menu.y > 0)
      _menu.y--;
  }
}


void  RendererInterface::updatePlayerList()
{
  AObjPlayer *player;
  std::vector<size_t> inv;
  std::stringstream   id;
  int  i;

  _listPlayer.erase(_listPlayer.begin(), _listPlayer.end());
  if (_cord->get("selPlayer") != -1)
  {
    id.str("");
    id << _cord->get("selPlayer");

    player = _map->getPlayer(_cord->get("selPlayer"));
    inv = player->getInventory();
    for (i = 0; i < 7; i++)
    {
      _listPlayer.push_back(new ListCont(*_itemSprt[i], _itemName[i], inv[i]));
    }
  }
}

void  RendererInterface::updateCaseList()
{
  int  i;
  int  nb;

  _listCase.erase(_listCase.begin(), _listCase.end());

  if (_cord->get("selCase") != -1)
  {
    for (i = 0; i < 7; i++)
    {
      nb = _map->getItemNb(i, _cord->get("selCase.x"), _cord->get("selCase.y"));
      _listCase.push_back(new ListCont(*_itemSprt[i], _itemName[i], nb));
    }
  }
}

void  RendererInterface::updateTeamList()
{
  size_t i;

  _listTeam.erase(_listTeam.begin(), _listTeam.end());

  for (i = 0; i < _teamNames->size(); i++)
  {
    _listTeam.push_back(new ListCont(*_teamSprt[0], (*_teamNames)[i], _map->getPlayerNbTeam((*_teamNames)[i])));
  }
}

void  RendererInterface::updateBroadList()
{
  std::list<std::string>::iterator  it;
  int                               i = 0;

  _listBroad.erase(_listBroad.begin(), _listBroad.end());

  for (it = _broadcast->begin(); it != _broadcast->end(); it++)
  {
    _listBroad.push_back(new ListCont(_broadSprt, (*it), i++));
  }
}

void  RendererInterface::updateStatList()
{
  std::list<AObjPlayer*>::iterator it;
  std::stringstream                content;

  _listStat.erase(_listStat.begin(), _listStat.end());
  for (it = _map->getPlayer()->begin(); it != _map->getPlayer()->end(); it++)
  {
    content.str("");
    content << (*it)->getTeamName() << "    Lvl: " << (*it)->getLevel();
    _listStat.push_back(new ListCont(*_teamSprt[0], content.str(), (*it)->getId()));

  }
}

void  RendererInterface::updateItemList()
{
  int  i;
  int  nb;

  _listItem.erase(_listItem.begin(), _listItem.end());
  for (i = 0; i < 7; i++)
  {
    nb = _map->getItemNbAll(i);
    _listItem.push_back(new ListCont(*_itemSprt[i], _itemName[i], nb));
  }
}

void  RendererInterface::drawList(std::list<ListCont*> const &list)
{
  sf::Text                             name;
  sf::Text                             val;
  std::stringstream                    content;
  std::list<ListCont*>::const_iterator it;
  sf::Vector2<float>                   pos;
  int                                  i;

  if (_input->getEvent().type == sf::Event::KeyPressed && _input->getEvent().key.code == sf::Keyboard::Down)
    if (static_cast<int>(list.size()) >= _menu.h && _menu.y < static_cast<int>(list.size()) - _menu.h)
      _menu.y++;
  name.setFont(_res->loadFont("Main.ttf"));
  name.setCharacterSize(28);
  name.setColor(sf::Color::Cyan);
  val = name;
  it = list.begin();
  i = 0;
  while (i++ < _menu.y && it != list.end())
    it++;
  i = 0;
  while (it != list.end() && i < _menu.h)
  {
    pos.x = _cord->get("win.w") / 2 - 185;
    pos.y = _layout.y + 32 + (37 * i);
    _selBar.setPosition(pos);
    if (i != _menu.h - 1)
      _win->draw(_selBar);

    pos.x = _layout.x + 32 - ((*it)->_sprt.getTextureRect().width / 2);
    pos.y -= 4 + ((*it)->_sprt.getTextureRect().width / 2);
    (*it)->_sprt.setPosition(pos);
    _win->draw((*it)->_sprt);

    pos.x = _layout.x + 60;
    pos.y = _layout.y + 32 + (37 * i) - 24;

    content.str("");
    content << (*it)->_val;
    val.setString(content.str());
    val.setPosition(pos);
    _win->draw(val);

    pos.y += 3;

    pos.x += 44;
    name.setString((*it)->_name);
    name.setPosition(pos);
    _win->draw(name);
    it++;
    i++;
  }
}

void  RendererInterface::drawBackground()
{
  _win->draw(_outbackL);
  _win->draw(_outbackR);
  _win->draw(_inback);
}


void  RendererInterface::drawContent()
{
  switch (_menu.x)
  {
    case 0:
      drawStatList();
      break;
    case 1:
      drawTeamList();
      break;
    case 2:
      drawItemList();
      break;
    case 3:
      drawBroadList();
      break;
    case 4:
      drawCaseList();
      break;
    case 5:
      drawPlayerList();
      break;
    default:
      break;
  }
  _refresh = false;
}

void  RendererInterface::drawMenu()
{
  sf::Vector2<float>                   pos;

  _categoryText.setString(_categoryName[_menu.x]);

  pos.x = _cord->get("win.w") / 2 - _categoryText.getLocalBounds().width / 2;
  pos.y = _cord->get("win.h") - 32;

  _categoryText.setPosition(pos);
  _win->draw(_categoryText);

}

void  RendererInterface::draw()
{

  drawBackground();
  drawContent();
  drawMenu();


}

void  RendererInterface::drawPlayerList()
{
  drawList(_listPlayer);

}

void  RendererInterface::drawCaseList()
{
  drawList(_listCase);

}

void  RendererInterface::drawTeamList()
{
  drawList(_listTeam);

}

void  RendererInterface::drawBroadList()
{
  drawList(_listBroad);

}

void  RendererInterface::drawStatList()
{
  drawList(_listStat);

}

void  RendererInterface::drawItemList()
{
  drawList(_listItem);

}
