#ifndef AOBJITEM_HH_
#define AOBJITEM_HH_

#include "System.hh"
#include "object/AObject.hh"

enum  eItemType
{
  FOOD,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME
};

class AObjItem : public AObject
{
protected:
  sf::Sprite   _sprtShadow;


  CordRect  _origin;
  size_t    _stp;
  size_t    _introT;
public:
  AObjItem(AObjModule const &core, int, int, int, int);
  virtual ~AObjItem();

  void         updateItem();
  void         renderItem();

  virtual void update();
  virtual void render();

  CordRect const &getOrigin() const;
  void            setOrigin(CordRect const &);
};

#endif
