#ifndef STONEDERAUMERE_HH_
#define STONEDERAUMERE_HH_

#include "System.hh"
#include "object/AObjItemStone.hh"

class  StoneDeraumere : public AObjItemStone
{
public:
  StoneDeraumere(AObjModule const &, int, int, int, int);
  ~StoneDeraumere();

  void    update();
  void    render();
};

#endif
