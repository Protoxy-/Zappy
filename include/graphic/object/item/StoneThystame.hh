#ifndef STONETHYSTAME_HH_
#define STONETHYSTAME_HH_

#include "System.hh"
#include "object/AObjItemStone.hh"

class  StoneThystame : public AObjItemStone
{
public:
  StoneThystame(AObjModule const &, int, int, int, int);
  ~StoneThystame();

  void    update();
  void    render();
};

#endif
