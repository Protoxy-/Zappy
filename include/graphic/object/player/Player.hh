#ifndef PLAYER_HH_
#define PLAYER_HH_

#include "System.hh"
#include "object/AObjPlayer.hh"

class  ObjPlayer : public AObjPlayer
{
  int   _stp;
  int   _actionStp;
  int   _actionTime;

public:
  ObjPlayer(AObjModule const &, int, int, int, int);
  ~ObjPlayer();

  void    initCordValues();
  void    updateColor();
  void    update();
  void    move();
  void    anim();

  void    render();
};

#endif
