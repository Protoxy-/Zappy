#ifndef CAMERA_HH_
# define CAMERA_HH_

# include "System.hh"
# include "engine/GraphicCore.hh"

class             Camera
{
  sf::RenderWindow *_win;

  CordManager     *_cord;
  InputManager    *_input;

  std::vector<bool> *_layerRefresh;

  sf::View        _view;

  CordRect        _camera;
  CordRect        _angle;

public:
  Camera(GraphicCore const &);
  ~Camera();

  void  init();

  void  updatePosition();
  void  updatePositionFromPlayer();
  void  updateAngle();
  void  updateZoom();
  void  update();
};

#endif // !CAMERA_HH_
