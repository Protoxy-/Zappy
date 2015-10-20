#ifndef STONESIBUR_HH_
#define STONESIBUR_HH_

#include "System.hh"
#include "object/AObjItemStone.hh"

class  StoneSibur : public AObjItemStone
{
public:
  StoneSibur(AObjModule const &, int, int, int, int);
  ~StoneSibur();

  void    update();
  void    render();
};

#endif
