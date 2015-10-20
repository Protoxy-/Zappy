#ifndef AObjITEMSTONE_HH_
#define AObjITEMSTONE_HH_

#include "System.hh"
#include "object/AObjItem.hh"

class AObjItemStone : public AObjItem
{
protected:


public:
  AObjItemStone(AObjModule const &core, int, int, int, int);
  virtual ~AObjItemStone();

  void    initCordValues();
  virtual void update();
  virtual void render();
};

#endif
