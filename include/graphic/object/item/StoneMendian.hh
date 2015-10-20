#ifndef STONEMENDIAN_HH_
#define STONEMENDIAN_HH_

#include "System.hh"
#include "object/AObjItemStone.hh"

class  StoneMendian : public AObjItemStone
{
public:
  StoneMendian(AObjModule const &, int, int, int, int);
  ~StoneMendian();

  void    update();
  void    render();
};

#endif
