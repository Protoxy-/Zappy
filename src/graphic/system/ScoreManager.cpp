#include "system/ScoreManager.hh"

ScoreManager::ScoreManager() :
  AFileVarsManager()
{
  _path = "save/score";
  _defPath = "res/configs/score";
}

ScoreManager::~ScoreManager()
{

}

std::map<std::string, std::vector<int> *>   const &ScoreManager::getList()
{
  return _vars;
}

void          ScoreManager::addScore(std::string const &name, int val)
{
  std::vector<int>  *vec = new std::vector<int>;

  vec->push_back(val);
  _vars.insert(std::make_pair(name, vec));
}
