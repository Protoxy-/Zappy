#include "system/CordRect.hh"

CordRect::CordRect(int _x, int _y, int _w, int _h)
{
  x = _x;
  y = _y;
  w = _w;
  h = _h;
}

CordRect::CordRect()
{
  x = 0;
  y = 0;
  w = 0;
  h = 0;
}

CordRect::~CordRect()
{

}

CordRect const &CordRect::operator=(CordRect const &other)
{
  x = other.x;
  y = other.y;
  w = other.w;
  h = other.h;
  return *this;
}
