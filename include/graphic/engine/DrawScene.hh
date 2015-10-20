#ifndef DRAWSCENE_HH_
#define DRAWSCENE_HH_

#include "System.hh"
#include "object/ObjIncludes.hh"

class   DrawScene
{
  Data                *data;
  std::list<Object*>  *objs;
  std::list<Object*>  top;
  std::list<Object*>  back;
  SDL_Surface         *screen;

public:
  DrawScene(Data *);
  ~DrawScene();

  void  backgroundEffect();
  void  background();
  void  refreshLayer(int);
  void  refreshAllLayer();
  void  scene();
};

#endif
