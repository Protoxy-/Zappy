#ifndef CORDRECT_HH_
# define CORDRECT_HH_

# include "System.hh"

class             CordRect
{
public:
  int             x;
  int             y;
  int             w;
  int             h;

  CordRect(int, int, int, int);
  CordRect();
  ~CordRect();

  CordRect const &operator=(CordRect const &);
};

#endif // !CORDRECT_HH_
