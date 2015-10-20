#ifndef GROUND_HH_
#define GROUND_HH_

#include "System.hh"
#include "object/AObjEnv.hh"

class  ObjGround : public AObjEnv
{
public:
  ObjGround(AObjModule const &, int, int, int, int);
  ~ObjGround();

  void    initCordValues();
  void    update();
  void    render();
};

#endif
