#ifndef STONEPHIRAS_HH_
#define STONEPHIRAS_HH_

#include "System.hh"
#include "object/AObjItemStone.hh"

class  StonePhiras : public AObjItemStone
{
public:
  StonePhiras(AObjModule const &, int, int, int, int);
  ~StonePhiras();

  void    update();
  void    render();
};

#endif
