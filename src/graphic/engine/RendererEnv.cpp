#include "engine/RendererEnv.hh"

RendererEnv::RendererEnv(GraphicCore const &core) :
  ARenderer(core)
{
  int rd = rand() % 3;
  if (rd == 0)
    _back.setTexture(_res->loadImage("back/sky.jpg"));
  else if (rd == 0)
    _back.setTexture(_res->loadImage("back/sky1.jpg"));
  else
    _back.setTexture(_res->loadImage("back/sky2.jpg"));
}

RendererEnv::~RendererEnv()
{

}


void  RendererEnv::update()
{

}

void  RendererEnv::draw()
{
  drawBackground();
  drawClouds();
}

void  RendererEnv::drawBackground()
{
  sf::Vector2<float>  pos;
  int           depth;
  int           i;
  int           j;
  int           w;
  int           h;

  depth = 5;
  w = _back.getTextureRect().width;
  h = _back.getTextureRect().height;
  for (i = 0; i * w < static_cast<int>(_win->getSize().x) + w; i++)
  {
    for (j = 0; j * h < static_cast<int>(_win->getSize().y) + h; j++)
    {
      pos.x = i * w - ((_cord->get("camera.x") / depth) % w);
      pos.y = j * h - ((_cord->get("camera.y") / depth) % h);
      _back.setPosition(pos);
      _win->draw(_back);
    }
  }

}

void  RendererEnv::drawClouds()
{

}
