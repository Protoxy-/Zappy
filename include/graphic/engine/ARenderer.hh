#ifndef ARENDERER_HH_
# define ARENDERER_HH_

# include "System.hh"
# include "engine/GraphicCore.hh"

class             ARenderer : public GraphicCore
{
public:
  ARenderer(GraphicCore const &);
  virtual ~ARenderer();

  virtual void  update();
  virtual void  draw();
};

#endif // !ARENDERER_HH_
