#include "core/AObjModule.hh"

AObjModule::AObjModule(GraphicCore const &core)
{
  _input = core.getInput();
  _config = core.getConfig();
  _cord = core.getCord();
  _win = core.getWin();
  _res = core.getRes();
  _layers = core.getLayers();
}

AObjModule::AObjModule(AObjModule const &other)
{
  _input = other._input;
  _config = other._config;
  _cord = other._cord;
  _win = other._win;
  _res = other._res;
  _layers = other._layers;
}

AObjModule::~AObjModule()
{

}
