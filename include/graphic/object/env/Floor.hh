#ifndef FLOOR_HH_
#define FLOOR_HH_

#include "System.hh"
#include "object/AObjEnv.hh"

class  ObjFloor : public AObjEnv
{
public:
  ObjFloor(AObjModule const &, int, int, int, int);
  ~ObjFloor();

  void    initCordValues();
  void    update();
  void    render();

  void    checkMousePos();

};

#endif
