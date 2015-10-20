#ifndef AOBJENV_HH_
#define AOBJENV_HH_

#include "System.hh"
#include "object/AObject.hh"

class AObjEnv : public AObject
{
protected:


public:
  AObjEnv(AObjModule const &core, int, int, int, int);
  virtual ~AObjEnv();

  virtual void update();
  virtual void render();
};

#endif
