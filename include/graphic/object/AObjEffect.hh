#ifndef AOBJEFFECT_HH_
#define AOBJEFFECT_HH_

#include "System.hh"
#include "object/AObject.hh"

class  AObjEffect : public AObject
{
protected:

public:
  AObjEffect(AObjModule const &core, int, int, int, int);
  virtual ~AObjEffect();

  virtual void update();
  virtual void render();
};

#endif
