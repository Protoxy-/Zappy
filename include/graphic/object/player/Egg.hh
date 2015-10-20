#ifndef EGG_HH_
#define EGG_HH_

#include "System.hh"
#include "object/AObjPlayer.hh"

class  ObjEgg : public AObjPlayer
{
public:
  ObjEgg(AObjModule const &, int, int, int, int);
  ~ObjEgg();

  void    initCordValues();
  void    update();
  void    render();
};

#endif
