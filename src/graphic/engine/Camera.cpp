#include "engine/Camera.hh"

Camera::Camera(GraphicCore const &core)
{
  _cord = core.getCord();
  _input = core.getInput();
  _win = core.getWin();
  _layerRefresh = core.getLayerRefresh();
}

Camera::~Camera()
{

}

void   Camera::init()
{
  _camera.w = _cord->get("camView.w");
  _camera.h = _cord->get("camView.h");
  _camera.x = _camera.w / 2;
  _camera.y = _camera.h / 2;

  sf::Vector2<float>    center(_camera.x, _camera.y);
  sf::Vector2<float>    half(_cord->get("win.w"), _cord->get("win.h"));

  _angle.x = _cord->get("angle.x");
  _angle.y = 0;
  _angle.w = _cord->get("zoom.x");
  _angle.h = _cord->get("zoom.y");
}

void   Camera::updatePosition()
{
  CordRect win;
  int      vec;


  win.w = (_cord->get("win.w"));
  win.h = (_cord->get("win.h"));
  win.x = (win.w * ((48 - _angle.w) + 48) / 48);
  win.y = (win.h * ((48 - _angle.w) + 48) / 48);

  if ((_input->getMousePos().y < 100 || _input->getMousePos().y > win.h - 100))
  {
    if (_input->getMousePos().x < win.w / 2)
    {
      vec = win.w / 2 - _input->getMousePos().x;
      vec /= 10;
      if (_camera.x - win.x / 2 > 0)
        _camera.x -= vec * _cord->get("scroll.x") / 100;
    }
    else
    {
      vec = win.w / 2 - (win.w - _input->getMousePos().x);
      vec /= 10;
      if (_camera.x + win.x / 2 < _camera.w)
        _camera.x += vec * _cord->get("scroll.x") / 100;
    }

    if (_input->getMousePos().y < 100)
    {

      vec = 100 - _input->getMousePos().y;
      if (_camera.y - win.y / 2 > 0)
        _camera.y -= vec * _cord->get("scroll.y") / 100;
    }
    else
    {
      vec = 100 - (win.h - _input->getMousePos().y);
      if (_camera.y + win.y / 2 < _camera.h + 300)
        _camera.y += vec * _cord->get("scroll.y") / 100;
    }
  }

  if ((_input->getMousePos().x < 100 || _input->getMousePos().x > win.w - 100) &&
      (_input->getMousePos().y > 100 && _input->getMousePos().y < win.h - 100))
  {
    if (_input->getMousePos().x < win.w / 2)
    {
      vec = 100 - _input->getMousePos().x;
      if (_camera.x - (win.x) / 2 > 0)
        _camera.x -= vec * _cord->get("scroll.x") / 100;
    }
    else
    {
      vec = 100 - (win.w - _input->getMousePos().x);
      if (_camera.x + (win.x) / 2 < _camera.w)
        _camera.x += vec * _cord->get("scroll.x") / 100;
    }

    if (_input->getMousePos().y < 100)
    {
      vec = win.h / 2 - _input->getMousePos().y;
      vec /= 8;
      if (_camera.y - (win.y) / 2 > 0)
        _camera.y -= vec * _cord->get("scroll.x") / 100;
    }
    else
    {
      vec = win.h / 2 - (win.h - _input->getMousePos().y);
      vec /= 8;
      if (_camera.y + (win.y) / 2 < _camera.h + 300)
        _camera.y += vec * _cord->get("scroll.x") / 100;
    }
  }
  _cord->set("camera", _camera);
}

void   Camera::updatePositionFromPlayer()
{
  CordRect win;

  _camera.x = _cord->get("selPlayer.w") + TILE / 2;
  _camera.y = _cord->get("selPlayer.h") + 150;
  _cord->set("camera", _camera);
}

void  Camera::updateAngle()
{
  int i;


  if (_input->getKey() == sf::Keyboard::Space)
  {
    _angle.x += 1;
    if (_angle.x >= 4)
      _angle.x = 0;
    _cord->set("angle", _angle.x);
    for (i = 0; i < _cord->get("layer.h"); i++)
      (*_layerRefresh)[i] = false;
  }
}

void  Camera::updateZoom()
{
  if (_input->getEvent().key.code == sf::Keyboard::Add || _input->getEvent().key.code == sf::Keyboard::P)
  if (_angle.w < _cord->get("zoom.h"))
  {
    _angle.w += 1;
    _cord->set("zoom", _angle.w);
  }
  if (_input->getEvent().key.code == sf::Keyboard::Subtract || _input->getEvent().key.code == sf::Keyboard::M)
  if (_angle.w > _cord->get("zoom.w"))
  {
    _angle.w -= 1;
    _cord->set("zoom", _angle.w);
  }
}

void  Camera::update()
{
  if (_input->getMouse().isButtonPressed(sf::Mouse::Button::Right))
    _cord->set("selPlayer", -1);
  if (_cord->get("selPlayer") == -1)
    updatePosition();
  else
    updatePositionFromPlayer();
  updateAngle();
  updateZoom();
}
