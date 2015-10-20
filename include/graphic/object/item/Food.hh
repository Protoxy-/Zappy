#ifndef FOOD_HH_
#define FOOD_HH_

#include "System.hh"
#include "object/AObjItemStone.hh"

class  ObjFood : public AObjItem
{
public:
  ObjFood(AObjModule const &, int, int, int, int);
  ~ObjFood();

  void    update();
  void    render();
};

#endif
