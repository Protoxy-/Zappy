#include "engine/DrawScene.hh"

DrawScene::DrawScene(Data *_data)
{
  data = _data;
  screen = data->getScreen();
}

DrawScene::~DrawScene()
{
}

void     DrawScene::backgroundEffect()
{

}

void     DrawScene::background()
{
  SDL_Surface   *top;
  SDL_Surface   *midl;
  SDL_Surface   *back;
  SDL_Rect      pos;
  int           i;
  int           j;

  back = data->getSprite("BackSky");
  for (i = 0; i * back->w < data->get("win").w + back->w; i++)
  {
    for (j = 0; j * back->h < data->get("win").h + back->h; j++)
    {
      pos.x = i * back->w - ((data->getCord("camera").x / 2) % back->w);
      pos.y = j * back->h - ((data->getCord("camera").y / 2) % back->h);
      SDL_BlitSurface(back, NULL, screen, &pos);
    }
  }
}

void    DrawScene::refreshLayer(int layer)
{
  std::list<Object*>            *objs;
  std::list<Object*>::iterator  it;
  int                           find;
  int                           depth;

  SDL_FillRect(data->getLayer(layer), NULL, data->getColor("clear"));
  objs = data->getObjs();
  depth = 0;
  find = 0;
  while (depth < 1000)
  {
    for (it = objs->begin(); it != objs->end(); it++)
    {
      if ((*it)->getDepth() == depth && (*it)->getLayer() == layer)
      {
        (*it)->render();
        find++;
      }
    }
    if (find == objs->size())
      break;
    depth++;
  }
}

void    DrawScene::refreshAllLayer()
{
  std::list<Object*>            *objs;
  std::list<Object*>::iterator  it;
  int                           find;
  int                           depth;

  int i;

  for (i = 0; i < 10; i++)
  {
    SDL_FillRect(data->getLayer(i), NULL, data->getColor("clear"));
  }
  objs = data->getObjs();
  depth = 0;
  find = 0;
  while (depth < 1000)
  {
    i = 0;
    for (it = objs->begin(); it != objs->end(); it++)
    {
      if ((*it)->getDepth() == depth)
      {
        (*it)->render();
        find++;
      }
      i++;
    }
    if (find == objs->size())
      break;
    depth++;
  }
}

void    DrawScene::scene()
{
  SDL_Rect  layerView;
  SDL_Rect  pos;
  int       i;

    pos.w = data->getCord("angle").w * screen->w / TILE;
    pos.h = data->getCord("angle").h * screen->h / TILE;

    layerView.w = screen->w * TILE / data->getCord("angle").w;
    layerView.h = screen->h * TILE / data->getCord("angle").h;

    if (layerView.w > data->getCord("camera").w)
      layerView.w = data->getCord("camera").w;
    if (layerView.h > data->getCord("camera").h)
      layerView.h = data->getCord("camera").h;

    layerView.x = data->getCord("camera").x;
    layerView.y = data->getCord("camera").y;

    layerView.x -= layerView.w / 2;
    layerView.y -= layerView.h / 2;

    pos.x = screen->w / 2 - pos.w / 2;
    pos.y = screen->h / 2 - pos.h / 2;

  for (i = 0; i < 2; i++)
  {
    SDL_BlitScaled(data->getLayer(i), &layerView, screen, &pos);
  }

}
