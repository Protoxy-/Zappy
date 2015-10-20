#ifndef STONELINEMATE_HH_
#define STONELINEMATE_HH_

#include "System.hh"
#include "object/AObjItemStone.hh"

class  StoneLinemate : public AObjItemStone
{
public:
  StoneLinemate(AObjModule const &, int, int, int, int);
  ~StoneLinemate();

  void    update();
  void    render();
};

#endif
