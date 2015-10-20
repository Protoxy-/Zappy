#ifndef CLOUD_HH_
#define CLOUD_HH_

#include "System.hh"
#include "object/AObjEffect.hh"

class  ObjCloud : public AObjEffect
{
public:
  ObjCloud(AObjModule const &, int, int, int, int);
  ~ObjCloud();

  void    initCordValues();
  void    update();
  void    render();
};

#endif
